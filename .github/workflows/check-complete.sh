#!/bin/bash
set -e

if grep -q vigneshesv *.md; then
  echo "Replace all text having vigneshesv with your input"
  exit 1
fi
