/* FUN_801648e8
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x801648e8  body 0x801648e8..0x80164a1b  size 308 B
 * body sha256 73b8644264a37ad635900167ca85229320ae7eaebc89dece5c27525021ac2fde
 * provider record sha256 f7911b8aac0b03ce4aae562dabc544106c2f9bac30bdd8a291559a8384bf86ce
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801648e8(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  short sVar2;
  char cVar3;
  int iVar4;
  
  bVar1 = *(byte *)(param_1 + 6);
  iVar4 = *(int *)(param_1 + 0x250);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    func_0x80077adc(0x4030001,param_1 + 0x28);
    func_0x80052d10(0x35,0xf0,0x28,0);
    *(undefined4 *)(param_1 + 0x1e8) = 0x30000;
    _DAT_800e10ec = _DAT_800e10ec | 0x4000000;
    *(undefined1 *)(param_1 + 7) = 0;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  }
  if (*(byte *)(param_1 + 7) < 3) {
    FUN_80164e5c(*(undefined1 *)(param_1 + 7));
    *(char *)(param_1 + 7) = *(char *)(param_1 + 7) + '\x01';
  }
  sVar2 = func_0x80032d14((int)*(short *)(iVar4 + 0x2a),(int)*(short *)(iVar4 + 0x32),
                          (int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32));
  func_0x80032ef4(param_1,(int)sVar2,0x80);
  cVar3 = func_0x80089d54(param_1,param_2,param_3,0x400);
  *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar3;
  return;
}
