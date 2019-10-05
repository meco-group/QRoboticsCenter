import os, requests, sys, json, re

MODE = sys.argv[1]

# define those environment variables before calling the script
USER = os.environ['USER']
TOKEN = os.environ['TOKEN']
REPO = os.environ['REPO']
TAG = os.environ['TAG']
if TAG.startswith('refs/tags/'):
    TAG = TAG[10:]

ENDPOINT = "https://api.github.com/"

def tag_to_release(name):
    url_ = ENDPOINT+"repos/"+REPO+"/releases/tags/"+name
    r = requests.get(url=url_, auth=(USER, TOKEN))
    try:
        id = r.json()['id']
        return r.json()
    except:
        return None

def get_ref(tagname):
    url_ = ENDPOINT+"repos/"+REPO+"/git/refs/tags/"+tagname
    r = requests.get(url=url_, auth=(USER, TOKEN))
    try:
        rj = r.json()['url']
        return r.json()
    except:
        return None

def get_tag(sha):
    url_ = ENDPOINT+"repos/"+REPO+"/git/tags/"+sha
    r = requests.get(url=url_, auth=(USER, TOKEN))
    try:
        rj = r.json()['url']
        return r.json()
    except:
        return None

if MODE == "delete-release":
    # DELETES A RELEASE by calling script with arguments:
    #   1) MODE: 'delete-release'

    release = tag_to_release(TAG)
    if release is not None:
        ENDPOINT += "repos/"+REPO+"/releases/"
        ENDPOINT += str(release['id'])
        r = requests.delete(url=ENDPOINT, auth=(USER, TOKEN))
    else:
        print "Cannot find tag \"%s\", skipping deletion." % TAG

elif MODE == "update-tag":
    # UPDATES A TAG TO AN SHA by calling script with arguments:
    #     1) MODE: 'update-tag'
    #     2) SHA: the sha key the updated tag should point to

    if get_ref(TAG) is not None:
        SHA = sys.argv[2]
        DATA = { "sha": SHA, "force": True }
        ENDPOINT += "repos/"+REPO+"/git/refs/tags/"+TAG
        r = requests.patch(url=ENDPOINT, data=json.dumps(DATA), auth=(USER, TOKEN))
    else:
        print "Cannot find tag \"%s\", skipping update." % TAG

elif MODE == "create-develop-release":
    # CREATES A DEVELOP RELEASE by calling script with arguments:
    #     1) MODE: 'create-develop-release'

    if get_ref(TAG) is not None:
        DATA = {
            "tag_name": TAG, "name": "develop", "draft": False, "prerelease": True,
            "body": "This is a development release - use at your own risk."
        }
        ENDPOINT += "repos/"+REPO+"/releases"
        r = requests.post(url=ENDPOINT, data=json.dumps(DATA), auth=(USER, TOKEN))
    else:
        print "Cannot find tag \"%s\", skipping creation." % TAG

elif MODE == "create-release":
    # CREATES A RELEASE by calling script with arguments:
    #     1) MODE: 'create-release'

    ref_data = get_ref(TAG)
    if ref_data is not None:
        tag_data = get_tag(ref_data['object']['sha'])
        if tag_data is not None:
            BODY = tag_data['message']
            BODY += ("\n\nAuthor: " + tag_data['tagger']['name'] + "\nUTC: " + tag_data['tagger']['date'])
            print BODY
            DATA = {
                "tag_name": TAG, "name": TAG, "draft": False, "prerelease": False,
                "body": BODY
            }
            ENDPOINT += "repos/"+REPO+"/releases"
            r = requests.post(url=ENDPOINT, data=json.dumps(DATA), auth=(USER, TOKEN))
        else:
            print "Cannot find tag \"%s\", skipping creation." % TAG
    else:
        print "Cannot find tag \"%s\", skipping creation." % TAG

elif MODE == "upload-assets":
    # UPLOADS ASSET TO A RELEASE by calling script with arguments:
    #     1) MODE: 'upload-assets'
    #     2) NAME: filename to use for the uploaded file
    #     3) ASSET: path to zip file to upload

    assert len(sys.argv) == 4, "3 arguments reguired."
    FILENAME = sys.argv[2]
    FILE = sys.argv[3]

    if not os.path.isfile(FILE):
        print "Provided file does not seem to exist (%s), skipping upload." % os.path.abspath(FILE)
    else:
        release = tag_to_release(TAG)
        if release is not None:
            URL = release['upload_url']
            URL = re.sub('\{.*\}', '', URL) + "?name=" + FILENAME + ".zip"
            DATA = open(FILE, 'rb')
            HEADER = { 'Content-Type': 'application/zip' }
            r = requests.post(URL, headers=HEADER, data=DATA, auth=(USER, TOKEN))
        else:
            print "Cannot find a release bound to tag \"%s\", skipping upload." % TAG

else:
    raise Exception("Cannot find MODE command.")
