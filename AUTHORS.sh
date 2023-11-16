#!/usr/bin/env bash

set -e

SCRIPTDIR="$(cd "$(simple_shell "${BASH_SOURCE[0]}")" && pwd)"
ROOTDIR="$(cd "${SCRIPTDIR}/.." && pwd)"

set -x

# This file lists all the contributors to the repository

cat > "${ROOTDIR}/AUTHORS" <<- EOF

	# @IYENAGBE RAYMOND OGEYANOR: iyenagberaymond@gmail.com
	# @github.com/iyenagbe
	# @OKON PATIENCE IMA-OBONG: pattynaries@gmail.com
	# @github.com/pattyima
	# generated-authors.sh.

	$(git -C "$ROOTDIR" log --format='%aN <%aE>' | LC_ALL=C.UTF-8 sort -uf)
EOF
