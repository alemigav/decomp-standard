/* FUN_801656ac
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x801656ac  body 0x801656ac..0x8016592b  size 640 B
 * body sha256 2a362b72c91d6085a437ab33210a79de15e78dae6caeb87eec916c5576d9cc32
 * provider record sha256 ce1f9d3bfb284e2197e0a406a36d67b9f90a3a27413f67a9583bcdc174d8305f
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801656ac(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  
  uVar4 = param_1[0x94];
  uVar2 = func_0x80033144(param_1,uVar4);
  uVar2 = uVar2 & 0xff;
  switch(*(undefined1 *)((int)param_1 + 6)) {
  case 0:
    *(undefined1 *)((int)param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x7d) = 0;
    param_1[0x7a] = ((*(byte *)((int)param_1 + 5) & 1) + 3) * 0x1000000 + 0x300;
    *param_1 = *param_1 | 10;
    func_0x80077adc((uVar2 + 1) * 0x10000 | 0x4000001,param_1 + 10);
    *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) | 0x12;
  case 1:
    if (uVar2 == 0) {
      func_0x80032dbc(param_1,*(undefined4 *)(uVar4 + 0x28),*(undefined4 *)(uVar4 + 0x30),0x40);
    }
    else {
      FUN_80162ac8(param_1,*(undefined4 *)(uVar4 + 0x28),*(undefined4 *)(uVar4 + 0x30),0x40);
    }
    if ((*(byte *)((int)param_1 + 0x1e9) < 6) || (DAT_800dfbe8 != '\0')) {
      func_0x80089d54(param_1,param_2,param_3,0x400);
    }
    if (*(char *)((int)param_1 + 0x1e9) == '\x1a') {
      cVar3 = *(char *)((int)param_1 + 6) + '\x01';
LAB_80165908:
      *(char *)((int)param_1 + 6) = cVar3;
    }
    break;
  case 2:
    func_0x80077adc((uVar2 + 1) * 0x10000 | 0x4000001,param_1 + 10);
    param_1[0x7a] = 0x100300;
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
  case 3:
    if (uVar2 == 0) {
      func_0x80032dbc(param_1,*(undefined4 *)(uVar4 + 0x28),*(undefined4 *)(uVar4 + 0x30),0x10);
    }
    else {
      FUN_80162ac8(param_1,*(undefined4 *)(uVar4 + 0x28),*(undefined4 *)(uVar4 + 0x30),0x10);
    }
    cVar3 = func_0x80089d54(param_1,param_1[0x89],param_1[0x8a],0x400);
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar3;
    break;
  case 4:
    sVar1 = *(short *)(param_1 + 0x7d);
    *(short *)(param_1 + 0x7d) = sVar1 + 1;
    if ((short)(sVar1 + 1) < 0x24) {
      return;
    }
    cVar3 = *(char *)((int)param_1 + 6) + '\x01';
    goto LAB_80165908;
  case 5:
    func_0x80077adc((uVar2 + 1) * 0x10000 | 0x4000001,param_1 + 10);
    param_1[0x7a] = 0x5000300;
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
  case 6:
    cVar3 = func_0x80089d54(param_1,param_1[0x89],param_1[0x8a],0x400);
    cVar3 = *(char *)((int)param_1 + 6) + cVar3;
    *(char *)((int)param_1 + 6) = cVar3;
    if (*(char *)((int)param_1 + 0x1e9) != '\f') {
      return;
    }
    cVar3 = cVar3 + '\x01';
    goto LAB_80165908;
  default:
    break;
  }
  return;
}
