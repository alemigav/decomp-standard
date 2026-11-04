/* FUN_8016703c
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x8016703c  body 0x8016703c..0x801671eb  size 432 B
 * body sha256 15ffd3fe60c43aa01ea31789aa87224934cb8a14db4ce6911fcf9163e6d33941
 * provider record sha256 c22e97c9749ec1fa095f4111200093b4707a7ed0506d84d8686bff6ea66221b9
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016703c(int param_1,uint param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  short local_50;
  short local_4e;
  short local_4c;
  undefined2 local_48;
  undefined2 local_46;
  undefined2 local_44;
  undefined1 auStack_40 [32];
  
  iVar3 = (param_3 & 0x7f) * 6;
  local_4e = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                             (int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32));
  iVar5 = *(int *)(param_1 + 0x234) + (param_2 & 0xff) * 0x178;
  bVar1 = (&DAT_80167ff4)[iVar3];
  iVar4 = (int)local_4e;
  if ((bVar1 & 0x80) == 0) {
    local_50 = 0;
    local_4c = 0;
    func_0x80040e58(&local_50,auStack_40);
    local_44 = 0;
    local_46 = 0;
    local_48 = 0;
    bVar2 = *(byte *)(param_1 + 0x2be);
    if (bVar2 == 1) {
      local_46 = 800;
    }
    else if ((bVar2 != 0) && (bVar2 < 4)) {
      local_48 = 400;
    }
    func_0x8004276c(auStack_40,&local_48,&local_50);
    local_50 = local_50 + *(short *)(iVar5 + 0x4e);
    local_4e = local_4e + *(short *)(iVar5 + 0x52);
    local_4c = local_4c + *(short *)(iVar5 + 0x56);
    if ((param_3 & 0x80) != 0) {
      local_4e = *(short *)(param_1 + 0x1a8);
    }
    iVar5 = -0x7ff16fd8;
  }
  else {
    iVar5 = iVar5 + 0x38;
    local_50 = 0;
    local_4e = -100;
    local_4c = 0;
  }
  func_0x80037780((bVar1 & 0x7f) << 0x18 | (uint)(byte)(&DAT_80167ff5)[iVar3] << 0x10 |
                  (uint)*(ushort *)(&DAT_80167ff8 + iVar3),iVar4,iVar5,&local_50);
  return;
}
