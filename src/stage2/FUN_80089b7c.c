/* FUN_80089b7c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80089b7c  body 0x80089b7c..0x80089c3b  size 192 B
 * body sha256 a94fbda8410826d3c2feaab70f7fea8b59b35f3944f412a99f2fc9dcdcbc4611
 * provider record sha256 3474a40f5f30d304f6240f9fa4f0d88099023b15bc3624c44645f0e331c22f8a
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80089b7c(uint *param_1)

{
  undefined2 uVar1;
  uint uVar2;
  
  if ((*(ushort *)((int)param_1 + 0x136) & 0x7fff) != 0) {
    *(ushort *)((int)param_1 + 0x136) = *(ushort *)((int)param_1 + 0x136) - 1;
    *(short *)((int)param_1 + 0x132) =
         *(short *)((int)param_1 + 0x132) + (short)*(char *)((int)param_1 + 0x135);
    *(short *)(param_1 + 0x4c) = *(short *)(param_1 + 0x4c) + (short)*(char *)(param_1 + 0x4d);
    if (*(short *)((int)param_1 + 0x136) == -0x8000) {
      uVar2 = *param_1;
      if ((DAT_800e9012 & 8) != 0) {
        uVar2 = uVar2 | 0x1062;
      }
      *param_1 = uVar2;
      *(undefined2 *)(param_1 + 10) = 0;
      *(undefined2 *)((int)param_1 + 0x11e) = 0;
      *(undefined2 *)(param_1 + 0xb) = 0;
      *(undefined2 *)((int)param_1 + 0x2a) = 0;
      *(undefined1 *)((int)param_1 + 0x111) = 0x1e;
      *(undefined2 *)((int)param_1 + 0x2e) = 0;
      uVar1 = *(undefined2 *)(DAT_800df938 + 0x66);
      *(undefined2 *)((int)param_1 + 0x32) = 0x400;
      *(undefined2 *)(param_1 + 0xc) = uVar1;
    }
  }
  return;
}
