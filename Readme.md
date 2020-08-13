# I-AM implementation in C

https://github.com/davidnunez/I-AM

## Files
### iam.c

Human-readable, with comments.

### iam_no_comments.c

Human-readable, without comments.

### iam_obfuscated.c

Obfuscated, with comments.

## Compilation

All source files complile via `[clang, gcc] <file>`.

Likely C89 compatable. If Windows has `stdio.h`, `stdlib.h`, and `time.h` then
it works on Windows too.

## Usage

`./iam <FILE>`

Where `FILE` is a source file containing **only** ` ` for an empty grid cell, and
`.` for full grid cells. Especially don't include `\`.

## License

(c) 2020 github.com/imtira

    The author of this work hereby waives all claim of copyright (economic and moral) in this work and
    immediately places it in the public domain; it may be used, distorted or destroyed in any manner
    whatsoever without further attribution or notice to the creator.