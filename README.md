<h1>
  <div align="center">
    <br />
    <br />
    <b><em>birno</em></b>
    <br />
    <br />
    &nbsp;
  </div>
</h1>
<br />
<br />

Command-line heat map for binary files.

*birno* visually renders raw bytes for
fun and absolutely no profit.

<br />
<br />
<div align="center">
<img
  alt="Example using birno against itself"
  src="docs/example.gif"
  width="672"
>
</div>
<br />
<br />


## Features

- Command-line tool
- Read binary input into *stdin*
- Maximum colors. *birno* Uses 24-bit
  truecolor support in modern terminals.
- Multiple, perceptually uniform color
  schemes to choose from

That's it! See [As Compared to
X](#as-compared-to-x) for more featureful
alternatives and [Roadmap](#roadmap) for
where *birno* is heading.


## Installation

Pre-built packages are not available yet.

First install the requisites:

* Clang 16

Then, build from source:

```sh
$ git clone https://github.com/sullvn/birno.git
$ cd birno
$ make
```


## As Compared to X

*birno*'s real purpose is as a tiny
project to refresh myself with modern
C++23. So you will probably be better
served by one of these:

- [**binvis.io**][0] is a binary visualizer
  web app. Retains visual locality and has
  some neat semantic coloring options.
  In contrast, *birno* has almost no
  features and is a terminal program.
- [**binocle**][1] is a tweakable desktop
  GUI. *birno* has the same perceptually 
  uniform color schemes.
- [**veles**][2] is very featureful binary
  analysis and visualization desktop GUI.
  Can do 3-dimensional visualization.
  *birno* just does 1,2-dimensional
  visualisation.


## Roadmap

1. Publish pre-built binaries and packages
2. Maybe port to Rust?


## You May Also Like

- [**pvw**][3] – Command-line tool which
  interactively previews command outputs
- [**shai**][4] – Command-line assistant
  using AI
- [**cowbox**][5] – Safely run programs
  without your files getting borked


<div align="center">
  <br />
  <br />
  <br />
  <br />
  🔥🗺️
  <br />
  <br />
  <br />
  <br />
  &nbsp;
</div>


[0]: https://binvis.io/#/
[1]: https://github.com/sharkdp/binocle
[2]: https://veles.io
[3]: https://github.com/sullvn/pvw
[4]: https://github.com/sullvn/shai
[5]: https://github.com/sullvn/cowbox


