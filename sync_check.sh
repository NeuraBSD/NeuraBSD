#!/bin/ksh
/*	$NeuraBSD: sync_check.sh, v 1.1 2026/02/07 16:35:00 codeakrobat Exp $	*/

#
# Copyright (c) 2026 Daniel Hilbert <lead@neurabsd.org>
#
# Permission to use, copy, modify, and distribute this software for any
# purpose with or without fee is hereby granted, provided that the above
# copyright notice and this permission notice appear in all copies.
#
# THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
# WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
# MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
# ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
# WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
# ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
# OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
#

##
# @file sync_check.sh
# @brief Synchronizes the MASTER-REPO with GitHub and checks for core dumps.
# @brief Synchronisiert das MASTER-REPO mit GitHub und prüft auf Core Dumps.
#
# This script ensures that build artifacts and core files are removed 
# before pushing to the NeuraBSD organization.
# Dieses Skript stellt sicher, dass Build-Artefakte und Core-Dateien 
# entfernt werden, bevor in die NeuraBSD-Organisation gepusht wird.
#

# --- Configuration / Konfiguration ---
REPO_DIR="$HOME/neurabsd"

##
# @brief Removes unwanted files / Entfernt unerwünschte Dateien.
#
cleanup() {
	echo "--> Cleaning up / Aufräumen..."
	
	# Remove core dumps / Core Dumps entfernen
	find "$REPO_DIR" -name "*.core" -delete
}

##
# @brief Synchronizes with GitHub / Synchronisiert mit GitHub.
#
sync_repo() {
	echo "--> Starting Sync / Starte Synchronisation..."
	cd "$REPO_DIR" || exit
	
	git add .
	git commit -m "Automated Sync: $(date +'%Y-%m-%d %H:%M:%S')"
	git push origin main
}

# --- Execution / Ausführung ---
cleanup
sync_repo

echo "--> Done / Fertig."
