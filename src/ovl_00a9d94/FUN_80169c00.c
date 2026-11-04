/* FUN_80169c00
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x80169c00  body 0x80169c00..0x80169f7b  size 892 B
 * body sha256 84bb9313408acd7979ba9ae4b9e366db12224a5fbb88875463b5ffbe722826cb
 * provider record sha256 53d7d5f51a8d08d7dd93a5d7759115ac77f1c2a92997b6c5bb945f2c1cd58225
 * callees 11 direct (11 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80169c00(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar4;
  uint uVar1;
  uint uVar2;
  char cVar5;
  int iVar3;
  uint uVar6;
  short local_20;
  short local_1e;
  short local_1c;
  
  switch(*(undefined1 *)((int)param_1 + 6)) {
  case 0:
    param_1[0x7a] = 0x1000700;
    *(undefined1 *)((int)param_1 + 6) = 1;
    _DAT_800e110c = _DAT_800e110c | 0x40;
    *(undefined1 *)(param_1 + 0x97) = 1;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
  case 1:
    param_1[10] = param_1[10] + ((int)((int)*(short *)(param_1 + 0x80) - param_1[10]) >> 1);
    param_1[0xc] = param_1[0xc] + ((int)((int)*(short *)(param_1 + 0x81) - param_1[0xc]) >> 1);
    func_0x80032ef4(param_1,(int)*(short *)((int)param_1 + 0x1f6),0x100);
    func_0x80089d54(param_1,param_2,param_3,0x200);
    if (*(char *)((int)param_1 + 0x1e9) == '\b') {
      *(undefined1 *)((int)param_1 + 6) = 2;
      *(undefined2 *)((int)param_1 + 0x66) = *(undefined2 *)((int)param_1 + 0x1f6);
      func_0x80077adc(0x4010001,param_1 + 10);
    }
    break;
  case 2:
    _DAT_800e1196 = _DAT_800e1196 + 0x800;
    func_0x8003331c(param_1,param_2,param_3,0);
    _DAT_800e1196 = _DAT_800e1196 + -0x800;
    iVar3 = func_0x80089d54(param_1,param_2,param_3,0x200);
    if (iVar3 != 0) {
      *(undefined1 *)((int)param_1 + 6) = 3;
    }
    break;
  case 3:
    param_1[0x7a] = 0x2000000;
    *(undefined1 *)((int)param_1 + 6) = 4;
    *(short *)((int)param_1 + 0x66) = *(short *)((int)param_1 + 0x66) + 300;
    *param_1 = *param_1 & 0xfffffff7;
  case 4:
    if (*(byte *)((int)param_1 + 0x1e9) < 10) {
      uVar4 = func_0x80033604(param_1);
      local_20 = (uVar4 & 0xff) * -2 + 0x100;
      uVar4 = func_0x80033604();
      local_1e = (uVar4 & 0xff) * -2 + 0x100;
      uVar4 = func_0x80033604();
      local_1c = (uVar4 & 0xff) * -2 + 0x100;
      uVar6 = param_1[0x8d];
      uVar1 = func_0x80033604();
      uVar2 = func_0x80033604();
      func_0x80037780((uVar1 & 1) << 0x10 | (uVar2 & 0xff) * 2 + 0x830,
                      (int)*(short *)((int)param_1 + 0x66),uVar6 + 0x38,&local_20);
    }
    func_0x800334c8(param_1,param_2,param_3,0);
    *(short *)(param_1 + 0x78) = *(short *)(param_1 + 0x78) + (*(short *)(param_1 + 0x78) >> 1);
    cVar5 = func_0x80089d54(param_1,param_2,param_3,0x400);
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar5;
    func_0x80032b5c(param_1,0x800);
    if (*(char *)((int)param_1 + 0x1e9) == '\x03') {
      func_0x80077adc(0x4020001,param_1 + 10);
    }
    if ((*(uint *)param_1[0x85] & 0x10000) != 0) {
      func_0x80077f30(2,0,param_1);
      func_0x80052bd0(3,0);
      func_0x80052c6c(6,0xfa,0);
    }
    break;
  case 5:
    *(undefined1 *)((int)param_1 + 6) = 6;
    param_1[0x7a] = 0x6000700;
  case 6:
    iVar3 = func_0x80089d54(param_1,param_1[0x69],param_1[0x86],0x10200);
    if (iVar3 != 0) {
      param_1[1] = 0x1000000;
      *(undefined1 *)(param_1 + 0x97) = 0;
      *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
      _DAT_800e110c = _DAT_800e110c & 0xffffffbf;
    }
  }
  return;
}
