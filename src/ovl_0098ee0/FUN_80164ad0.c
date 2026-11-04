/* FUN_80164ad0
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x80164ad0  body 0x80164ad0..0x80164eb7  size 1000 B
 * body sha256 9f9caba9d9777f4bf0dd8f4d8270bfe116629af7d925138e6c4ff6b1ab4dacf4
 * provider record sha256 6448e23009aacb1409e24ceb3df544b671a8057a6cefa9756dd370456bcbf471
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164ad0(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  
  switch(*(undefined1 *)((int)param_1 + 6)) {
  case 0:
    param_1[0xb] = 0xffff9e58;
    *(undefined2 *)(param_1 + 0x9c) = 0;
    *(undefined2 *)(param_1 + 0x7d) = 0;
    *param_1 = *param_1 | 10;
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
  case 1:
    if (*(short *)(param_1 + 0x9c) != 1) {
      return;
    }
    param_1[0xb] = 0xffffa240;
    param_1[0x7a] = 0xe330000;
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
  case 2:
    *(undefined1 *)(param_1 + 0x7a) = 0xe;
    *(undefined1 *)((int)param_1 + 0x1e9) = 0x33;
    func_0x80089d54(param_1,param_2,param_3,0x1000);
    uVar3 = param_1[0xb];
    param_1[0xb] = uVar3 + 1000;
    if (uVar3 + 1000 != 0xffffb9b0) {
      return;
    }
    break;
  case 3:
    *(undefined1 *)(param_1 + 0x7a) = 0xe;
    cVar2 = func_0x80089d54(param_1,param_2,param_3,0x1000);
    goto LAB_80164c08;
  case 4:
    if (*(short *)(param_1 + 0x9c) != 2) {
      return;
    }
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
  case 5:
    func_0x80036c68(param_1,1,0xf,0);
    if (*(short *)(param_1 + 0x9c) != 3) {
      return;
    }
    break;
  case 6:
    cVar2 = func_0x80036c68(param_1,9,0xf,0);
LAB_80164c08:
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar2;
    return;
  case 7:
    if (*(short *)(param_1 + 0x9c) != 4) {
      return;
    }
    param_1[0x7a] = 0x1000f00;
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
  case 8:
    *(undefined1 *)(param_1 + 0x7a) = 1;
    func_0x800334c8(param_1,param_1[0x8b],param_1[0x8c],0);
    uVar3 = param_1[0x8b];
    uVar4 = param_1[0x8c];
    uVar5 = 0x100;
    goto LAB_80164e84;
  case 9:
    if (*(short *)(param_1 + 0x9c) == 5) {
      param_1[0x7a] = 0x1000000;
      *(short *)((int)param_1 + 0x66) = *(short *)((int)param_1 + 0x66) + 0x800;
      *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
      func_0x80089d54(param_1,param_1[0x8b],param_1[0x8c],0x1000);
      return;
    }
    return;
  case 10:
    func_0x80036c68(param_1,8,3,0);
    if (*(short *)(param_1 + 0x9c) != 6) {
      return;
    }
    param_1[0x7a] = 0x2000300;
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
  case 0xb:
    *(undefined1 *)(param_1 + 0x7a) = 2;
    if (*(short *)(param_1 + 0x9c) == 7) {
      param_1[0x7a] = 0x3000300;
      *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
    }
    func_0x800334c8(param_1,param_1[0x8b],param_1[0x8c],0);
    iVar1 = func_0x80089d54(param_1,param_1[0x8b],param_1[0x8c],0x400);
    if (iVar1 == 0) {
      return;
    }
    *(undefined1 *)((int)param_1 + 0x1e9) = 0x19;
    return;
  case 0xc:
    *(undefined1 *)(param_1 + 0x7a) = 3;
    func_0x800334c8(param_1,param_1[0x8b],param_1[0x8c],0);
    iVar1 = func_0x80089d54(param_1,param_1[0x8b],param_1[0x8c],0x400);
    if (iVar1 != 0) {
      *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
    }
    goto LAB_80164ea0;
  case 0xd:
    if (*(short *)(param_1 + 0x9c) != 8) {
      return;
    }
    param_1[0x7a] = 0x4000000;
    *(short *)((int)param_1 + 0x66) = *(short *)((int)param_1 + 0x66) + 0x800;
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
  case 0xe:
    func_0x80089d54(param_1,param_1[0x8b],param_1[0x8c],0x1000);
    if (*(short *)(param_1 + 0x9c) != 8) {
      return;
    }
    cVar2 = *(char *)((int)param_1 + 6);
    param_1[0x7a] = 0x4000000;
    goto LAB_80164dfc;
  case 0xf:
    break;
  case 0x10:
    *(undefined1 *)(param_1 + 0x7a) = 4;
    func_0x800334c8(param_1,param_1[0x8b],param_1[0x8c],0);
    iVar1 = func_0x80089d54(param_1,param_1[0x8b],param_1[0x8c],0x1000);
    if (iVar1 != 0) {
      param_1[0x7a] = 0x300;
      *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
    }
    goto LAB_80164ea0;
  case 0x11:
    *(undefined1 *)(param_1 + 0x7a) = 0;
    func_0x800334c8(param_1,param_1[0x8b],param_1[0x8c],0);
    uVar3 = param_1[0x8b];
    uVar4 = param_1[0x8c];
    uVar5 = 0x400;
LAB_80164e84:
    cVar2 = func_0x80089d54(param_1,uVar3,uVar4,uVar5);
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar2;
LAB_80164ea0:
    func_0x80032b5c(param_1,0);
switchD_80164b00_default:
    return;
  default:
    goto switchD_80164b00_default;
  }
  cVar2 = *(char *)((int)param_1 + 6);
LAB_80164dfc:
  *(char *)((int)param_1 + 6) = cVar2 + '\x01';
  return;
}
