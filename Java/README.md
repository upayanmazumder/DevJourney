# Java

This directory contains Java exercises and course programs.

## Java formatting

The repository uses [google-java-format](https://github.com/google/google-java-format).
`.google-java-format-version` pins version 1.37.0 for local commands and CI.
`.google-java-format` declares the formatter options.

| Rule                      | Value                                                            |
| ------------------------- | ---------------------------------------------------------------- |
| Style                     | Google Java Style, not AOSP                                      |
| Block indentation         | 2 spaces, no tabs                                                |
| Continuation indentation  | 4 spaces                                                         |
| Column limit              | 100, with formatter-defined exceptions                           |
| Braces                    | Opening brace stays on the declaration or control statement line |
| Imports                   | Sort imports and remove unused imports                           |
| Comments and strings      | Apply the formatter's default Javadoc and long-string formatting |
| Encoding and line endings | UTF-8, LF, final newline, as declared in `.editorconfig`         |

The formatter controls layout. EditorConfig does not configure the formatter.
Do not use Prettier or an IDE's independent Java style for these sources.
Formatter defaults apply to rules not listed above.

### Installation

Use JDK 21 or newer. The JDK must support the source language version.
Install the pinned formatter on your PATH. For example, from the repository root:

```bash
version=$(cat .google-java-format-version)
mkdir -p "$HOME/.local/share/google-java-format" "$HOME/.local/bin"
curl --fail --show-error --location \
  "https://repo.maven.apache.org/maven2/com/google/googlejavaformat/google-java-format/$version/google-java-format-$version-all-deps.jar" \
  -o "$HOME/.local/share/google-java-format/google-java-format-$version.jar"
cat > "$HOME/.local/bin/google-java-format" <<EOF
#!/bin/sh
exec java -jar "$HOME/.local/share/google-java-format/google-java-format-$version.jar" "\$@"
EOF
chmod +x "$HOME/.local/bin/google-java-format"
export PATH="$HOME/.local/bin:$PATH"
google-java-format --version
```

These instructions install a user-local command. They do not require root access.
The repository rejects formatter versions that differ from the pin.

### Commands

Run these commands from the repository root:

```bash
pnpm format:java
pnpm format:java:check
```

The first command formats all tracked and non-ignored untracked Java files.
The second command reports formatting differences without changing files.
Both commands also work without pnpm:

```bash
./format --java --all
./format --java --all --check
```

For selected files, use the same options explicitly:

```bash
google-java-format @.google-java-format --replace 'path/to/Program.java'
```

The existing pre-commit hook uses this version and these options for staged Java files.
The Format Check workflow installs JDK 21 and the pinned formatter.
Its Java check fails on formatting drift or invalid Java syntax.
Its repository check also includes Java alongside the other languages.
