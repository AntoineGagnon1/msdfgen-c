# msdfgen-c

C bindings for [msdfgen](https://github.com/Chlumsky/msdfgen/).

msdfgen version : **1.11.0**

## Usage

Copy the content of the `bindings/` directory in your project, and link against `msdfgen-c.lib`

To regenerate the bindings copy your version of msdfgen into the `msdfgen/` directory and build the `msdfgen-c` project

## Demo

The project contains a demo that will open a font, and render the msdf texture for the letter `A` in `output.png`

To run the demo compile and run `demo/main.c`
