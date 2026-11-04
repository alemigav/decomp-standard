/* FUN_80165f7c
 * image   ovl_009dd02 (ovl), base 0x80161cf0
 * address 0x80165f7c  body 0x80165f7c..0x80166143  size 456 B
 * body sha256 45f5b93c37e6995e4530b4314bd008de5840d70e2e56e130671afc1af01e3c54
 * provider record sha256 9e1e98066cab3b1a5e0b376a625a98c2b4860e90fe0c5d32b6441a041b110a9e
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165f7c(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  bVar2 = *(byte *)(param_1 + 6);
  uVar6 = *(undefined4 *)(param_1 + 0x250);
  if (bVar2 == 1) goto LAB_801660a8;
  if (bVar2 < 2) {
    if (bVar2 != 0) goto LAB_801660a8;
    *(undefined4 *)(param_1 + 0x1e8) = 0x1001f00;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined1 *)(param_1 + 0x206) = 0x1f;
    func_0x80052c6c(0x14,0x78,0);
    uVar4 = 0x1e;
    uVar5 = 0x14;
  }
  else {
    if (bVar2 != 2) goto LAB_801660a8;
    if (*(char *)(param_1 + 7) == '\0') {
      *(undefined1 *)(param_1 + 7) = 1;
      *(undefined1 *)(param_1 + 0x207) = 1;
    }
    cVar1 = *(char *)(param_1 + 0x207);
    *(char *)(param_1 + 0x207) = cVar1 + -1;
    if (cVar1 != '\x01') goto LAB_801660a8;
    *(undefined2 *)(param_1 + 6) = 0x100;
    func_0x80077adc(0x4020001,param_1 + 0x28);
    FUN_80166b98(param_1,0,8);
    func_0x80052bd0(10,0);
    func_0x80052c6c(6,0xfa,2);
    func_0x80052c6c(0x14,0x78,8);
    uVar4 = 0x14;
    uVar5 = 0x1c;
  }
  func_0x80052d10(uVar4,0x78,0x28,uVar5);
LAB_801660a8:
  cVar1 = *(char *)(param_1 + 0x206);
  if (cVar1 == 0) {
    iVar3 = 0;
  }
  else {
    *(char *)(param_1 + 0x206) = *(char *)(param_1 + 0x206) + -1;
    iVar3 = (cVar1 * 0x11c) / 0x1f;
  }
  FUN_80166ea0(param_1,uVar6,iVar3 + 0x4a3);
  iVar3 = func_0x80089d54(param_1,param_2,param_3,0x80);
  if (iVar3 != 0) {
    *(undefined1 *)(param_1 + 0x1ea) = 0x1f;
  }
  return;
}
