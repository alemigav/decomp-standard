/* func_800b1ebc
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800b1ebc  body 0x800b1ebc..0x800b1fbf  size 260 B
 * body sha256 0f7fb3841255fb69080b2f12ff83b416367b2f99684477e0297b988a739394c8
 * provider record sha256 dbac4b4ac0bca33ab36440a3f5220d73f9d177a142d01f1e3e040a983e0145bf
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
undefined4 func_800b1ebc(undefined4 param_1,undefined1 param_2)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  
  uVar5 = 0xffffffff;
  if (DAT_80136310 != '\0') {
    FUN_800a5678();
    uVar2 = FUN_800af0d4(param_1);
    while (uVar2 != 0xffffffff) {
      uVar4 = uVar2 & 0xff;
      iVar3 = uVar4 * 0x1a0;
      if (*(uint *)(&DAT_801444a8 + iVar3) != uVar2) break;
      if ((*(uint *)(&DAT_8014446c + iVar3) & 2) == 0) {
        uVar1 = *(undefined1 *)(iVar3 + -0x7febbb6d);
      }
      else {
        uVar1 = *(undefined1 *)(iVar3 + -0x7febbb63);
      }
      FUN_800ac614(0x40,uVar4,uVar1,param_2);
      uVar5 = 0;
      uVar2 = *(uint *)(uVar4 * 0x1a0 + -0x7febbba8);
    }
    FUN_800a56c0();
  }
  return uVar5;
}
