/* FUN_8016a408
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x8016a408  body 0x8016a408..0x8016a87b  size 1140 B
 * body sha256 51121e66e9b1f08b817ffa27f5c4ad28ef6eb1278985b14ed722a7bb0eba63c5
 * provider record sha256 e8c0ee435e417a02fb5ad417e1c6a2bcbaa7df5b0bb7278ee25055fc8703d951
 * callees 12 direct (12 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016a408(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  ushort uVar4;
  uint uVar2;
  uint uVar3;
  char cVar5;
  uint *puVar6;
  uint uVar7;
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
    func_0x80077adc(0x4010001,param_1 + 10);
    *param_1 = *param_1 | 2;
    func_0x80052c6c(0x1e,0x78,5);
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
    iVar1 = func_0x80089d54(param_1,param_2,param_3,0x200);
    if (iVar1 != 0) {
      *(undefined1 *)((int)param_1 + 6) = 3;
    }
    if (*(char *)((int)param_1 + 0x1e9) == '\x1e') {
      func_0x80077adc(0x4000001,param_1 + 10);
      puVar6 = (uint *)param_1[0x8d];
      puVar6[0x4c] = 0x30;
      puVar6[0x4d] = 0x202020;
      *puVar6 = *puVar6 | 0x80;
      uVar2 = param_1[0x8d];
      *(uint *)(uVar2 + 0x178) = *(uint *)(uVar2 + 0x178) | 0x80;
      *(undefined4 *)(uVar2 + 0x2a8) = 0x30;
      *(undefined4 *)(uVar2 + 0x2ac) = 0x202020;
      uVar2 = param_1[0x8d];
      *(uint *)(uVar2 + 0x2f0) = *(uint *)(uVar2 + 0x2f0) | 0x80;
      *(undefined4 *)(uVar2 + 0x420) = 0x30;
      *(undefined4 *)(uVar2 + 0x424) = 0x202020;
      uVar2 = param_1[0x8d];
      *(uint *)(uVar2 + 0x758) = *(uint *)(uVar2 + 0x758) | 0x80;
      *(undefined4 *)(uVar2 + 0x888) = 0x30;
      *(undefined4 *)(uVar2 + 0x88c) = 0x202020;
      uVar2 = param_1[0x8d];
      *(uint *)(uVar2 + 0xbc0) = *(uint *)(uVar2 + 0xbc0) | 0x80;
      *(undefined4 *)(uVar2 + 0xcf0) = 0x30;
      *(undefined4 *)(uVar2 + 0xcf4) = 0x202020;
      uVar2 = param_1[0x8d];
      *(uint *)(uVar2 + 0xd38) = *(uint *)(uVar2 + 0xd38) | 0x80;
      *(undefined4 *)(uVar2 + 0xe68) = 0x30;
      *(undefined4 *)(uVar2 + 0xe6c) = 0x202020;
      uVar2 = param_1[0x8d];
      *(uint *)(uVar2 + 0x11a0) = *(uint *)(uVar2 + 0x11a0) | 0x80;
      *(undefined4 *)(uVar2 + 0x12d0) = 0x30;
      *(undefined4 *)(uVar2 + 0x12d4) = 0x202020;
    }
    break;
  case 3:
    param_1[0x7a] = 0x2000000;
    *(undefined1 *)((int)param_1 + 6) = 4;
    *(short *)((int)param_1 + 0x66) = *(short *)((int)param_1 + 0x66) + 100;
    *param_1 = *param_1 & 0xfffffff7;
  case 4:
    if (*(byte *)((int)param_1 + 0x1e9) < 10) {
      uVar4 = func_0x80033604();
      local_20 = (uVar4 & 0xff) * -2 + 0x100;
      uVar4 = func_0x80033604();
      local_1e = (uVar4 & 0xff) * -2 + 0x100;
      uVar4 = func_0x80033604();
      local_1c = (uVar4 & 0xff) * -2 + 0x100;
      uVar7 = param_1[0x8d];
      uVar2 = func_0x80033604();
      uVar3 = func_0x80033604();
      func_0x80037780((uVar2 & 1) << 0x10 | (uVar3 & 0xff) * 2 + 0x830,
                      (int)*(short *)((int)param_1 + 0x66),uVar7 + 0x38,&local_20);
    }
    if (*(char *)((int)param_1 + 0x1e9) == '\x03') {
      func_0x80077adc(0x4020001,param_1 + 10);
    }
    if ((*(uint *)param_1[0x85] & 0x10000) != 0) {
      func_0x80077f30(2,0,param_1);
      func_0x80052bd0(3,0);
      func_0x80052c6c(6,0xfa,0);
    }
    func_0x800334c8(param_1,param_2,param_3,0);
    func_0x80089d54(param_1,param_2,param_3,0x400);
    func_0x80032b5c(param_1,0x800);
    if (*(char *)((int)param_1 + 0x1e9) == '#') {
      *(undefined1 *)((int)param_1 + 6) = 5;
      param_1[0x7a] = 0x2550f00;
      func_0x80052bd0(5,0);
      func_0x80052c6c(5,0x78,0);
      func_0x80052d10(0x3c,0xfa,0,5);
    }
    break;
  case 5:
    cVar5 = func_0x80089d54(param_1,param_1[0x69],param_1[0x86],0x100);
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar5;
  }
  return;
}
