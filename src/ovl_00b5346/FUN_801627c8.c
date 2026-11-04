/* FUN_801627c8
 * image   ovl_00b5346 (ovl), base 0x80161cf0
 * address 0x801627c8  body 0x801627c8..0x801628ff  size 312 B
 * body sha256 26547eabc1c1b72f05c1965ab154de4fb6dde4260f1fc8a7bb25559df51cc333
 * provider record sha256 c0453d47f56f81a4537c1a7493b6322d4b005c21c8f086b62efff59f32a6133a
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801627c8(int param_1)

{
  byte bVar1;
  short sVar2;
  char cVar6;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  if (*(char *)(param_1 + 7) == '\0') {
    cVar6 = *(char *)(param_1 + 0x2b9) + -1;
    *(char *)(param_1 + 0x2b9) = cVar6;
    while (cVar6 != -1) {
      uVar3 = func_0x80033604();
      sVar2 = *(short *)(param_1 + 0x2ba);
      uVar4 = func_0x80033604();
      iVar5 = FUN_80162f34(param_1,0x6001,(int)sVar2 + ((uVar3 & 0xf) - 7) * 0x10,
                           (int)*(short *)(param_1 + 700) + ((uVar4 & 0xf) - 7) * 0x10);
      if (iVar5 == 0) break;
      *(undefined2 *)(iVar5 + 0x1e0) = *(undefined2 *)(param_1 + 0x2ba);
      *(undefined2 *)(iVar5 + 0x1e4) = *(undefined2 *)(param_1 + 700);
      uVar3 = func_0x80033604();
      bVar1 = (&DAT_80163074)[uVar3 & 7];
      *(ushort *)(param_1 + 500) = (ushort)bVar1;
      if (bVar1 != 0) {
        *(undefined1 *)(param_1 + 7) = 1;
        return;
      }
      cVar6 = *(char *)(param_1 + 0x2b9) + -1;
      *(char *)(param_1 + 0x2b9) = cVar6;
    }
    *(undefined1 *)(param_1 + 7) = 0;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  }
  else {
    sVar2 = *(short *)(param_1 + 500);
    *(short *)(param_1 + 500) = sVar2 + -1;
    if (sVar2 == 1) {
      *(undefined1 *)(param_1 + 7) = 0;
    }
  }
  return;
}
