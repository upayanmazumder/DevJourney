# DevJourney

[![Website](https://img.shields.io/badge/🌐%20Website-upayan.dev/devjourney-2563eb?style=flat-square&logo=google-chrome&logoColor=white)](https://upayan.dev/devjourney)
[![DeepWiki](https://img.shields.io/badge/📘%20DeepWiki-DevJourney-0ea5e9?style=flat-square&logo=bookstack&logoColor=white)](https://deepwiki.com/upayanmazumder/DevJourney)

[![wakatime](https://wakatime.com/badge/user/851ac76d-87ff-42ea-898a-fb8f3654c40f/project/300269be-5962-4e16-8086-716c67547ffd.svg)](https://wakatime.com/badge/user/851ac76d-87ff-42ea-898a-fb8f3654c40f/project/300269be-5962-4e16-8086-716c67547ffd)

[![CodeQL](https://github.com/upayanmazumder/DevJourney/actions/workflows/github-code-scanning/codeql/badge.svg?style=flat-square)](https://github.com/upayanmazumder/DevJourney/actions/workflows/github-code-scanning/codeql) [![Dependabot](https://github.com/upayanmazumder/DevJourney/actions/workflows/dependabot/dependabot-updates/badge.svg?style=flat-square)](https://github.com/upayanmazumder/DevJourney/actions/workflows/dependabot/dependabot-updates) [![Daily Tag](https://github.com/upayanmazumder/DevJourney/actions/workflows/daily%20tag%20creator.yml/badge.svg?style=flat-square)](https://github.com/upayanmazumder/DevJourney/actions/workflows/daily%20tag%20creator.yml)

[![Last Commit](https://img.shields.io/github/last-commit/upayanmazumder/DevJourney?style=flat-square&color=22c55e&logo=git)](https://github.com/upayanmazumder/DevJourney/commits/main) [![Repo Size](https://img.shields.io/github/repo-size/upayanmazumder/DevJourney?style=flat-square&color=ef4444&logo=database)](https://github.com/upayanmazumder/DevJourney) [![Languages](https://img.shields.io/github/languages/count/upayanmazumder/DevJourney?style=flat-square&color=8b5cf6&logo=code)](https://github.com/upayanmazumder/DevJourney) [![Top Language](https://img.shields.io/github/languages/top/upayanmazumder/DevJourney?style=flat-square&color=f59e0b&logo=javascript)](https://github.com/upayanmazumder/DevJourney)

[![Issues](https://img.shields.io/github/issues/upayanmazumder/DevJourney?style=flat-square&color=ec4899&logo=github)](https://github.com/upayanmazumder/DevJourney/issues) [![Pull Requests](https://img.shields.io/github/issues-pr/upayanmazumder/DevJourney?style=flat-square&color=06b6d4&logo=git)](https://github.com/upayanmazumder/DevJourney/pulls) [![Contributors](https://img.shields.io/github/contributors/upayanmazumder/DevJourney?style=flat-square&color=10b981&logo=github)](https://github.com/upayanmazumder/DevJourney/graphs/contributors) [![Stars](https://img.shields.io/github/stars/upayanmazumder/DevJourney?style=flat-square&color=f97316&logo=starship)](https://github.com/upayanmazumder/DevJourney/stargazers) [![Forks](https://img.shields.io/github/forks/upayanmazumder/DevJourney?style=flat-square&color=3b82f6&logo=git)](https://github.com/upayanmazumder/DevJourney/network/members)

---

## What is it?

This repository is a collection of various pieces of code written in multiple languages. The code stored here is a mix of different projects, tests, and studies, each unrelated to the other.

## Purpose

The purpose of this repository is to store and document the diverse range of code I have written as part of my learning journey. It serves as a personal reference and a showcase of my progress and exploration in various programming languages.

## Tooling

### Package manager

JavaScript projects use [pnpm](https://pnpm.io/) only. Each manifest declares
`"packageManager": "pnpm@11.28.6"`, and only `pnpm-lock.yaml` files are tracked.
CI rejects `package-lock.json`, `yarn.lock` and `bun.lock` if they appear.

### Formatting

`prettier` is pinned in the root `package.json`, so run `pnpm install` once at
the repository root to get the exact version CI uses. Styles are declared per
language:

| Language                                | Config                                |
| --------------------------------------- | ------------------------------------- |
| JS, TS, JSON, CSS, HTML, Markdown, YAML | `.prettierrc.json`, `.prettierignore` |
| C, C++                                  | `.clang-format`                       |
| Python                                  | `pyproject.toml` (`[tool.black]`)     |
| Java                                    | `google-java-format` (fixed style)    |
| Go                                      | `gofmt` (fixed style)                 |
| Editors                                 | `.editorconfig`                       |

`./format` formats staged files, `./format --check` verifies them, and
`./format --all` formats every tracked file. CI runs `./format --all --check`
over the whole tree, which is kept fully formatted.

### Git hooks

Run `./setup-hooks` once after cloning:

| Hook         | Checks                                                                                                          |
| ------------ | --------------------------------------------------------------------------------------------------------------- |
| `pre-commit` | rejects build artifacts, compiled binaries, files over 10 MB and obvious credentials, then formats staged files |
| `commit-msg` | enforces Conventional Commits (`fix(scope): subject`)                                                           |
| `pre-push`   | runs `pnpm install --frozen-lockfile` and the build script for every pnpm project touched by the push           |

Bypass a hook with `--no-verify` only when necessary.

### Continuous integration

| Workflow                                                     | Scope                                                                              |
| ------------------------------------------------------------ | ---------------------------------------------------------------------------------- |
| Repository Guard                                             | tracked artifacts, pnpm-only lockfiles, `packageManager` presence, oversized files |
| Format Check                                                 | formatting of the entire tree                                                      |
| Unit Tests                                                   | Vitest suites of the Vite React apps                                               |
| JS Projects Install & Build Check                            | frozen install and build for every non-Docker JS project                           |
| Docker Image CI (learning-react, learning-qwik, html.nodejs) | image build per affected project                                                   |
| Dependency Review                                            | blocks PRs that add high or critical severity dependencies                         |

`main` requires `guard`, `format-check` and `dependency-review` to pass before a
pull request can merge.

## License

This project is licensed under the MIT License - see the [LICENSE](./LICENSE) file for details.
