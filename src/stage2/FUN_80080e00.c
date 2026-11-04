/* FUN_80080e00
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80080e00  body 0x80080e00..0x80080ee3  size 228 B
 * body sha256 1b659d4dbfe2cedf56381f21b18d34c56ba33bb9c12c7d92e7138931616822dd
 * provider record sha256 ce31ceaae3d381861598d9cfbad1a2ae3420d3be94b81fde8cbdc045dc811284
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80080e00(undefined4 param_1,short param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  char cVar3;
  
  iVar1 = DAT_800e13ec;
  if (*(char *)(DAT_800e13ec + 0x26f) == '\0') {
    *(short *)(DAT_800e13ec + 0x1f2) = *(short *)(DAT_800e13ec + 0x1f2) - param_2;
    DAT_800e9010 = DAT_800e9010 - param_2;
    *(undefined4 *)(iVar1 + 4) = 0x2000000;
    if ((param_3 & 2) != 0) {
      *(undefined1 *)(iVar1 + 5) = 2;
    }
    cVar3 = FUN_80033144(param_1,iVar1);
    *(char *)(iVar1 + 5) = *(char *)(iVar1 + 5) + cVar3;
    if ((param_3 & 1) == 0) {
      uVar2 = 0;
      if (param_3 == 0) {
        if (*(short *)(iVar1 + 0x1f2) < 0) {
          *(undefined4 *)(iVar1 + 4) = 0x3000000;
          uVar2 = 2;
        }
        else {
          uVar2 = 0;
        }
      }
    }
    else {
      uVar2 = 0;
      if (*(short *)(iVar1 + 0x1f2) < 0) {
        *(undefined2 *)(iVar1 + 0x1f2) = 0;
        DAT_800e9010 = 0;
      }
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}
