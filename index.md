---
layout: default
title: Home
---
# Latest release

### {{ site.github.latest_release.name }}:

{% for asset in site.github.latest_release.assets %}
{% if asset.name contains 'linux' %}
{% assign name = "Linux" %}
{% elsif asset.name contains 'windows' %}
{% assign name = "Windows" %}
{% else %}
{% assign name = "Mac" %}
{% endif %}<a href="{{ asset.browser_download_url }}">{{ name }}</a>{% assign idx = forloop.index %}{% assign nr = site.github.latest_release.assets | size %}{% if idx != nr %} - {% endif %}{% endfor %}

### develop:
{% assign prereleases = site.github.releases | where: "prerelease", true %}
{% assign develop = prereleases[0] %}
{% for asset in develop.assets %}
{% if asset.name contains 'linux' %}
{% assign name = "Linux" %}
{% elsif asset.name contains 'windows' %}
{% assign name = "Windows" %}
{% else %}
{% assign name = "Mac" %}
{% endif %}<a href="{{ asset.browser_download_url }}">{{ name }}</a>{% assign idx = forloop.index %}{% assign nr = site.github.latest_release.assets | size %}{% if idx != nr %} - {% endif %}{% endfor %}
