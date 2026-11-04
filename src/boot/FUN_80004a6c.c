/* FUN_80004a6c
 * image   boot (boot), base 0x80000480
 * address 0x80004a6c  body 0x80004a6c..0x80004b5b  size 240 B
 * body sha256 e325494c22b9ba3645bcbea90bf15ac7f59ddf936fffb767f3ce1109df26a89f
 * provider record sha256 602e6a9e85294ab23a6cedf99c2d01d31e2da9244333a6ba2379bb25f6d35d91
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80004a6c(undefined4 param_1,int param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (_DAT_8011a718 != 0) {
    _DAT_800e110c = _DAT_800e110c | 0x20;
    uVar1 = *(ushort *)(param_2 * 2 + _DAT_8011a718);
    _DAT_80012884 = 1;
    if ((uVar1 & 0x8000) == 0) {
      uVar3 = (uint)((ulonglong)((uint)DAT_80012888 * (uint)DAT_8011a28f) * 0x51eb851f >> 0x20);
      uVar2 = 16000;
    }
    else {
      uVar3 = (uint)((ulonglong)((uint)DAT_80012888 * (uint)DAT_8011a28f) * 0x51eb851f >> 0x20);
      uVar1 = uVar1 & 0x7fff;
      uVar2 = 8000;
    }
    _DAT_80012878 = func_0x800b3704(uVar1,uVar2,0x7f,uVar3 >> 5 & 0xff,0x3f,0,0);
  }
  return;
}
