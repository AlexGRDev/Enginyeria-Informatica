#!/bin/bash
input=$(cat)
p=$(jq -r '.tool_input.file_path // empty' <<<"$input")
[[ -z "$p" || "$p" == *"/../"* || "$p" == *"/.." ]] && { echo "Ruta inválida: $p" >&2; exit 2; }
root="/Users/alexg/Documents/Enginyeria-Informatica/.claude/worktrees"
case "$p" in
  "$root"/PRO1/*.md|"$root"/IC/*.md|"$root"/FM/*.md|"$root"/Fisica/*.md) exit 0 ;;
esac
echo "Fuera de alcance: branch-worker solo escribe .md dentro de worktrees de asignatura" >&2
exit 2
