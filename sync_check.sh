#!/bin/sh

# NeuraBSD Master-Repo Sync Check
# Author: CodeAkrobat (Daniel Hilbert)

REPO_DIR="/home/codeakrobat/neurabsd"
REMOTE="origin"
BRANCH="main" # Falls dein Haupt-Branch 'master' heißt, bitte anpassen

echo "--- NeuraBSD Sync Check ---"
cd "$REPO_DIR" || exit

# 1. Verbindung prüfen & Updates vom Server holen
echo "Prüfe auf Updates bei GitHub..."
git fetch $REMOTE

# 2. Status vergleichen
LOCAL=$(git rev-parse HEAD)
REMOTE_VAL=$(git rev-parse @{u})

if [ "$LOCAL" = "$REMOTE_VAL" ]; then
    echo "✅ Alles aktuell. Dein lokales MASTER-REPO ist auf dem neuesten Stand."
elif [ "$LOCAL" = "$(git merge-base HEAD @{u})" ]; then
    echo "⚠️  Update verfügbar! Jemand (oder du von woanders) hat Code gepusht."
    echo "Nutze 'git pull' um dein System zu aktualisieren."
else
    echo "🚀 Du hast lokale Änderungen, die noch nicht auf GitHub sind."
    echo "Nutze 'git push' um deine Arbeit als CodeAkrobat zu sichern."
fi

echo "--------------------------"
