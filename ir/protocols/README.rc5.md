# RC-5 overview
The command data is a Manchester-coded bitstream modulating a 36 kHz carrier. In RC5, Manchester
coded bits are defined as "Logic 1 is defined as an 889-µs space period followed by an 889-µs carrier modulated pulse period. Logic 0 is defined as an 889-µs carrier modulated pulse period followed by an 889-µs space period."

The IR command comprises of 14 bits:

- The RC5 data frame begins with two start logic 1 bits

- A control bit which toggles with each button press. This allows the receiving device to distinguish between two successive button presses (such as "1", "1" for "11") as opposed to the user simply holding down the button and the repeating commands being interrupted by a person walking by, for example.

- A five-bit system address that selects one of 32 possible systems.

- A six-bit command that (in conjunction with the field bit) represents one of the 128 possible RC-5 commands.

Since the repetition of the 36 kHz carrier is 27.778 μs and the duty factor is 25 %, the carrier pulse duration is 6.944 μs. Each bit of the RC-5 code word contains 32 carrier pulses, and an equal duration of silence, so the bit time is 64×27.778 μs = 1.778 ms, and the 14 symbols (bits) of a complete RC-5 code word take 24.889 ms to transmit. The code word is repeated every 113.778 ms (4096 ÷ 36 kHz) as long as a key remains pressed. (Again, please note that these timings are not strictly followed by all manufacturers, due to a lack of widespread distribution of accurate information on the RC-5 protocol.)

### Example TV power

See https://en.wikipedia.org/wiki/RC-5 for a list of addresses and commands.

#### IR command structure
```bash
| 1 start bit | 1 field bit | 1 control bit | 5 address bits | 6 command bits |
```

#### IR TV power command
```bash
| 1 | 1 | 0 | 0 0 0 0 0 | 0 0 1 1 0 0 |
```


### Carier wave example
Let one "w" = 32 pulses in an 889-µs space window, and let "." = an 889-µs space of no IR transmission. Remember, each bit contains 32 pulses where logical 1 is represented
by an 889-µs space period followed by an 889-µs carrier modulated pulse period. Logic 0 is defined as an 889-µs carrier modulated pulse period followed by an 889-µs space period.

#### IR TV power command
```bash
| 1 | 1 | 0 | 0 0 0 0 0 | 0 0 1 1 0 0 |
```

#### IR TV modulated power command
The pipes divide the bits and are not part of the modulated carrier wave. Each character (other
than the pipes) represents a time period of 889-µs.

w = 32 IR pulses at 36 kHz for time period of 889-µs
. = no IR transmission for time period of 889-µs
```bash
|.w |.w | w. | w. w. w. w. w. | w. w. .w .w w. w.|
| 1 | 1 | 0  | 0  0  0  0  0  | 0  0   1  1 0  0 |
```

#### IR TV raw modulated power command
```bash
.w.ww.w.w.w.w.w.w.w..w.ww.w.
```