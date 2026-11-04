/* FUN_8005c32c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005c32c  body 0x8005c32c..0x8005c3e7  size 188 B
 * body sha256 d47a343145523e57f8a256cb2149db797e523c8735688e1e646f80fe78acd598
 * provider record sha256 27e85611fbc312bc84921e35d0d63546b34c9db4f433cb72c7b5dcff0af917f0
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8005c32c(int param_1)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  
  if ((*(ushort *)(param_1 + 0x1aa) & 0xfff) == 0x12) {
    iVar3 = *(int *)(param_1 + 0x234) + 0x1780;
    if ((*(byte *)(param_1 + 8) & 1) != 0) {
      iVar3 = *(int *)(param_1 + 0x234) + 0x1d60;
    }
    if (*(char *)(iVar3 + 0x112) == '\0') {
      uVar1 = *(short *)(iVar3 + 0x11e) - 8;
      *(ushort *)(iVar3 + 0x11e) = uVar1;
      if ((int)((uint)uVar1 << 0x10) < 0) {
        *(undefined2 *)(iVar3 + 0x11e) = 0;
      }
    }
    else {
      sVar2 = *(short *)(iVar3 + 0x11e) + 0x20;
      *(short *)(iVar3 + 0x11e) = sVar2;
      if (0x200 < sVar2) {
        *(undefined2 *)(iVar3 + 0x11e) = 0x200;
      }
    }
    *(short *)(iVar3 + 0x5a) = *(short *)(iVar3 + 0x5a) + *(short *)(iVar3 + 0x11e);
    FUN_80040e58(iVar3 + 0x58,iVar3 + 8);
    *(undefined1 *)(iVar3 + 0x112) = 0;
  }
  return;
}
