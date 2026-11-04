/* FUN_80162098
 * image   ovl_0087352 (ovl), base 0x80161cf0
 * address 0x80162098  body 0x80162098..0x80162253  size 444 B
 * body sha256 4d37e89c7f0d91898dabf264282572cf96815543043530bf648b0fd13f3f13ff
 * provider record sha256 fef1ad61582931abe46a56f0d4290eceed0ebc10d8bd5d0dff653679a1cfe86f
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162098(int param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  uint uVar2;
  byte bVar3;
  undefined1 uVar4;
  char cVar5;
  undefined **ppuVar6;
  
  bVar1 = false;
  if ((*(char *)(param_1 + 700) == '\0') && (uVar2 = func_0x80033604(), (uVar2 & 0x1f) == 0)) {
    bVar3 = func_0x80033604();
    *(byte *)(param_1 + 700) = bVar3 & 0x7f;
    uVar4 = func_0x80065628();
    *(undefined1 *)(param_1 + 699) = uVar4;
  }
  if (_DAT_800e1322 < 0) {
    if (*(char *)(param_1 + 0x2bd) != '\0') {
      bVar1 = *(char *)(param_1 + 700) != '\0';
      *(char *)(param_1 + 0x2bd) = *(char *)(param_1 + 0x2bd) + -1;
    }
  }
  else if (((*(ushort *)(param_1 + 0x2c6) & 0x40) == 0) && (*(char *)(param_1 + 700) != '\0')) {
    bVar1 = true;
  }
  if (bVar1) {
    func_0x800653d0(param_1,&DAT_800e1158,*(undefined1 *)(param_1 + 699),1);
    cVar5 = *(char *)(param_1 + 700) + -1;
    *(char *)(param_1 + 700) = cVar5;
    if (cVar5 == -1) {
      *(undefined1 *)(param_1 + 699) = 0;
    }
  }
  else {
    func_0x800653d0(param_1,&DAT_800e1158,0,0);
  }
  if ((*(ushort *)(param_1 + 0x1aa) & 0x80) == 0) {
    (*(code *)(&PTR_FUN_80166590)[*(byte *)(param_1 + 5)])(param_1);
    bVar3 = *(byte *)(param_1 + 5);
    ppuVar6 = &PTR_FUN_801665cc;
  }
  else {
    (*(code *)(&PTR_FUN_80166608)[*(byte *)(param_1 + 5)])(param_1);
    bVar3 = *(byte *)(param_1 + 5);
    ppuVar6 = &PTR_FUN_80166644;
  }
  (*(code *)ppuVar6[bVar3])(param_1,param_2,param_3);
  return;
}
