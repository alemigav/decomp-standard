/* FUN_80074464
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80074464  body 0x80074464..0x800745c7  size 356 B
 * body sha256 3bffa454b3e97f2fc5fb51bfc93192a17e338a159bab2f809c7e097717d8d8c9
 * provider record sha256 9acdf88b671247d9ad348f87a05053653deeaddd614cd63011d07c65166cfdcd
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80074464(int param_1)

{
  short *psVar1;
  short sVar2;
  
  if ((*(byte *)(DAT_800df938 + 0x26f) & 0x80) == 0) {
    if ((*(ushort *)(DAT_800df938 + 0x1f0) & 2) == 0) {
      *(byte *)(DAT_800df938 + 0x26f) = *(byte *)(DAT_800df938 + 0x26f) | 0x80;
      *(short *)(DAT_800df938 + 0x1f2) = *(short *)(DAT_800df938 + 0x1f2) - *(short *)(param_1 + 2);
      if (*(short *)(DAT_800df938 + 0x1f2) < 0) {
        if (*(char *)(DAT_800df938 + 4) != '\x03') {
          *(undefined1 *)(DAT_800df938 + 4) = 3;
          *(undefined1 *)(DAT_800df938 + 5) = 0;
          *(undefined1 *)(DAT_800df938 + 6) = 0;
          *(undefined1 *)(DAT_800df938 + 7) = 0;
        }
      }
      else {
        *(undefined1 *)(DAT_800df938 + 4) = 2;
        *(undefined1 *)(DAT_800df938 + 5) = *(undefined1 *)(param_1 + 1);
        *(undefined1 *)(DAT_800df938 + 6) = 0;
        *(undefined1 *)(DAT_800df938 + 7) = 0;
        sVar2 = FUN_80032d14((int)(((uint)*(ushort *)(DAT_801152cc + 4) +
                                   (uint)(*(ushort *)(DAT_801152cc + 8) >> 1)) * 0x10000) >> 0x10,
                             (int)(((uint)*(ushort *)(DAT_801152cc + 6) +
                                   (uint)(*(ushort *)(DAT_801152cc + 10) >> 1)) * 0x10000) >> 0x10,
                             (int)*(short *)(DAT_800df938 + 0x2a),
                             (int)*(short *)(DAT_800df938 + 0x32));
        psVar1 = (short *)(DAT_800df938 + 0x66);
        *(undefined2 *)(DAT_800df938 + 0x1e0) = 200;
        FUN_80032b5c(DAT_800df938,(int)sVar2 - (int)*psVar1);
        FUN_80052bd0(4,0);
        FUN_80052c6c(10,0x96,0);
      }
    }
    else {
      *(ushort *)(DAT_800df938 + 0x1f0) = *(ushort *)(DAT_800df938 + 0x1f0) & 0xfffd;
    }
  }
  return 1;
}
