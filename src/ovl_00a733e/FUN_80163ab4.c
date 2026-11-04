/* FUN_80163ab4
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80163ab4  body 0x80163ab4..0x80163c2f  size 380 B
 * body sha256 46d832ee03b393a396ed01f3691ccb23ae4fc737ec3e1f9683421e1292302fd6
 * provider record sha256 20ea36cb729092c20c368b2de467eeb08c268cd705dca9cc47ecb3d9b27ff6ce
 * callees 8 direct (8 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163ab4(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (*(char *)(param_1 + 7) == '\0') {
    *(undefined1 *)(param_1 + 7) = 1;
    *(undefined1 *)(param_1 + 0x206) = 4;
    *(undefined1 *)(param_1 + 0x207) = 4;
  }
  func_0x800334c8(param_1,param_2,param_3,0);
  iVar1 = func_0x80089d54(param_1,param_2,param_3,0x100);
  if (iVar1 != 0) {
    *(undefined2 *)(param_1 + 6) = 0x200;
  }
  func_0x80032b5c(param_1,0);
  func_0x80033648(param_1);
  uVar3 = **(ushort **)(param_1 + 0x214) & 7;
  if (((**(ushort **)(param_1 + 0x214) & 7) != 0) && ((int)*(char *)(param_1 + 0x206) != uVar3)) {
    iVar1 = FUN_801677b0(param_1,uVar3 - 1);
    if (iVar1 != 0) {
      uVar2 = 0xd;
      if (uVar3 < 3) {
        uVar2 = 3;
      }
      func_0x80077d18(uVar2,param_1);
      *(char *)(param_1 + 0x206) = (char)uVar3;
      *(undefined1 *)(param_1 + 0x207) = 4;
    }
  }
  if (*(char *)(param_1 + 0x207) != '\0') {
    uVar3 = (uint)(short)(&DAT_80167d6c)[(*(char *)(param_1 + 0x206) + -1) * 2];
    if (*(char *)(param_1 + 0x206) < 3) {
      FUN_80167374(param_1,uVar3 + 1 & 0xff,1);
      uVar3 = uVar3 + 3;
    }
    FUN_80167374(param_1,uVar3 & 0xff,1);
    *(char *)(param_1 + 0x207) = *(char *)(param_1 + 0x207) + -1;
  }
  FUN_80163620(param_1,*(char *)((int)&DAT_80167d6c + *(char *)(param_1 + 0x206) * 4 + 1) + '\x01');
  return;
}
