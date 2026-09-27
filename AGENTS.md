# AGENTS.md

## Release Archive Workflow

For this repository, every future official version release must include a local archive step.

An official version release is not complete until Codex has created and validated a local archive snapshot from the published Git tag.

Required workflow for every future release `v<VERSION>`:

1. Complete implementation and validation.
2. Update version documentation.
3. Create the release commit.
4. Push `main` to `origin/main` without force-pushing.
5. Create the version tag `v<VERSION>`.
6. Push the version tag to `origin`.
7. Create `E:\Projekt_Arcade_Shooter\Archive\v<VERSION>` from the published Git tag only.
8. Do not copy the archive from the current working tree.
9. Prefer `git -c core.autocrlf=false archive` so archived files match the tag blobs exactly on Windows.
10. Add local-only `ARCHIVE_INFO.md` inside the archive folder with version, name, Git tag, full release commit hash, status, archive date, and immutable archive note.
11. Validate the archive against the tag: file list, blob contents, `VERSION`, central source files, no generated Unreal build folders, older archives unchanged, and clean Git working tree.

`Archive/` is local-only. Do not commit it, push it, or include it in release tags. Keep `Archive/` ignored through `.git/info/exclude` unless the project owner explicitly asks for a different strategy.

Do not change existing archive folders unless the user explicitly requests a repair.
