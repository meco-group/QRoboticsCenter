---
layout: default
title: CI/CD functionality
permalink: /ci-cd
---
# Outline
- The CI/CD is set up to automatically build binaries for Windows, Mac and Linux
- Running as a Microsoft Azure DevOps pipeline
- Binaries are *only* being built when one of the following occurs
  1. A commit to the `develop` branch is pushed
  2. A tag starting with `v` is pushed, e.g. `v1.0`


## `develop` builds
  - The `dev` tag is automatically moved to always point at the tip of `develop` (latest commit)
  - The `develop` pre-release is automatically built from this tag
  - The binaries are always updated to the latest CI/CD run, so once a pipeline is triggered by pushing to `develop`, the former binaries will be deleted


## Tagged commits
  - If you push a tag starting with `v`, the CI/CD pipeline will be triggered for a release
  - The release name will be the tag's name
  - The release message consists of the tag's message, appended with information on the author and the timestamp
  - If you want to update a release, update the tag locally (`git tag -f v5.0.0 -m "move tag around"`) and then force a remote update (`git push origin -f v5.0.0`); this will re-run a pipeline for this tag
