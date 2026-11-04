/* FUN_80162fdc
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x80162fdc  body 0x80162fdc..0x80163137  size 348 B
 * body sha256 71d7aa55fe101e1f2d8e5138c924a727c525449c3a9a2e3bc6f0e10dd26e1118
 * provider record sha256 9f2ebe6fe1365b831c8a33fddf7c091dc770b6e0992ce21bf88af5575996614a
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162fdc(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  if ((_DAT_800e113e != 0) && (DAT_800e139f == '\0')) {
    _DAT_800e1134 = 0x5020000;
    _DAT_800e1380 = param_1;
    cVar1 = func_0x80033144(param_1,&DAT_800e1130);
    if (cVar1 != '\0') {
      cVar1 = DAT_800e1135 + '\x01';
      _DAT_800e1135 = CONCAT12(cVar1,_DAT_800e1136);
    }
    if (*(int *)(param_1 + 0x30) < -8999) {
      if (*(int *)(param_1 + 0x28) < -0x3cef) {
        cVar1 = func_0x80033144(param_1,&DAT_800e1130);
        uVar2 = 0xc00;
        if (cVar1 == '\0') {
          uVar2 = 0x400;
        }
      }
      else {
        cVar1 = func_0x80033144(param_1,&DAT_800e1130);
        uVar2 = 0x800;
        if (cVar1 == '\0') {
          uVar2 = 0;
        }
      }
    }
    else {
      cVar1 = func_0x80033144(param_1,&DAT_800e1130);
      uVar2 = 0;
      if (cVar1 == '\0') {
        uVar2 = 0x800;
      }
    }
    func_0x80032ef4(&DAT_800e1130,uVar2,0x600);
    uVar2 = 0x3c;
    if ((*(ushort *)(param_1 + 0x2b4) & 0x20) != 0) {
      uVar2 = 0x1e;
    }
    FUN_8016525c(uVar2);
    *(undefined1 *)(param_1 + 0x2d4) = 0x46;
    *(undefined1 *)(param_1 + 0x2cd) = 0;
    FUN_801656e4();
  }
  return;
}
