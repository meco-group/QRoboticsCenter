---
layout: default
title: Home
---
# Get the latest release
## {{ site.github.latest_release.name }}

{% assign latest = site.github.latest_release %}
{% include release_matrix.html release=latest %}

<hr />

# For the adventurous
## Develop build
{% assign prereleases = site.github.releases | where: "prerelease", true %}
{% assign develop = prereleases[0] %}
{% include release_matrix.html release=develop %}
