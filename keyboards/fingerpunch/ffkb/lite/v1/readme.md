# ffkb lite

An ergonomic 30% keyboard

* Keyboard Maintainer: [sadekbaroudi](https://github.com/sadekbaroudi)

faux fox keyboard (ffkb) lite

Make example for this keyboard (after setting up your build environment):
```
    make fingerpunch/ffkb/lite/v1:default FP_INDICATOR_LED_ENABLE=yes
```

Don't forget to add ```CONVERT_TO=stemcell``` if using a stemcell controller.

You can also use ```FP_CONVERT_TO=svlinky``` if you are using a svlinky. This is not part of the general QMK converters framework. I added the logic in the firmware for this pcb directly.
If using a svlinky, also see the comments at the top of `keyboards/fingerpunch/ffkb/lite/rules.mk` and uncomment / comment the appropriate lines.

Options are:
```
    FP_INDICATOR_LED_ENABLE=yes
```

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
