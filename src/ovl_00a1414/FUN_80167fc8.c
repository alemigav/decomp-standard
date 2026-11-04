/* FUN_80167fc8
 * image   ovl_00a1414 (ovl), base 0x80161cf0
 * address 0x80167fc8  body 0x80167fc8..0x8016816b  size 420 B
 * body sha256 62d2436712192dfba05e0c0df71825702a376809739fc900d8bd10601c04ed3e
 * provider record sha256 8a8f9ff41f8bcdb624078c5715df23427f6b725fb4874cb9beaff6d5598326dc
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80167fc8(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  short sVar2;
  ushort uVar3;
  
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    *(undefined4 *)(param_1 + 0x1e8) = 0x1060300;
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x1e0) = 800;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    _DAT_800e110c = _DAT_800e110c | 0x40;
    *(undefined1 *)(param_1 + 0x25c) = 1;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
    func_0x80077adc(0x4010001,param_1 + 0x28);
  case 1:
    cVar1 = func_0x80089d54(param_1,param_2,param_3,0x400);
    sVar2 = *(short *)(param_1 + 0x1e0) + -0x96;
    *(short *)(param_1 + 0x1e0) = sVar2;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar1;
    if (sVar2 < 300) {
      *(undefined2 *)(param_1 + 0x1e0) = 300;
    }
    break;
  case 2:
    *(undefined4 *)(param_1 + 0x1e8) = 0x2000300;
    *(undefined1 *)(param_1 + 6) = 3;
  case 3:
    cVar1 = func_0x80089d54(param_1,param_2,param_3,0x400);
    uVar3 = *(short *)(param_1 + 0x1e0) - 0x14;
    *(ushort *)(param_1 + 0x1e0) = uVar3;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar1;
    if ((int)((uint)uVar3 << 0x10) < 0) {
      *(undefined2 *)(param_1 + 0x1e0) = 0;
    }
    break;
  case 4:
    *(undefined1 *)(param_1 + 0x25c) = 1;
    *(undefined4 *)(param_1 + 4) = 0x1000000;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) & 0x7f;
    _DAT_800e110c = _DAT_800e110c & 0xffffffbf;
  }
  func_0x80032b5c(param_1,0x800);
  return;
}
