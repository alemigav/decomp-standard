/* FUN_8007eed0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007eed0  body 0x8007eed0..0x8007ef93  size 196 B
 * body sha256 7dc3195572dd217c0e7977eb52e63a37f7900de30eecdca7e3a61258adbfd321
 * provider record sha256 25e13ca1e2f81be3f117318d66a3b191469b58490912e21ba4a359f4d14ec7d9
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8007ef64) */

void FUN_8007eed0(int param_1)

{
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined2 *)(param_1 + 500) = 0x3c;
  }
  if (*(short *)(param_1 + 500) != 0) {
    *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + -1;
  }
  if (*(ushort *)(param_1 + 0x2ba) < 200) {
    *(undefined4 *)(param_1 + 4) = 0x10b0000;
  }
  else if ((*(short *)(param_1 + 500) < 0x1e) && (1000 < *(ushort *)(param_1 + 0x2ba))) {
    *(undefined4 *)(param_1 + 4) = 0x10d0000;
  }
  else {
    if (*(short *)(param_1 + 500) == 0) {
      *(undefined4 *)(param_1 + 4) = 0x10d0000;
    }
    FUN_80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),
                 0xffffffd0);
  }
  return;
}
