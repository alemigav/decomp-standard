/* FUN_80162a08
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x80162a08  body 0x80162a08..0x80162c93  size 652 B
 * body sha256 47ddc268102a8a10ccca2a9ca450c8d967e4e1a036945abd998a7f304793ea98
 * provider record sha256 1467117694913f1e36582960b6cfa6bc15404093fd35145ca663baeff90a4860
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162a08(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  
  bVar1 = *(byte *)((int)param_1 + 6);
  if (bVar1 == 1) goto LAB_80162b78;
  if (1 < bVar1) {
    if (bVar1 == 2) {
      func_0x8003331c(param_1,param_2,param_3,0);
      iVar3 = func_0x80036c68(param_1,5,0,0);
      if (iVar3 == 0) {
        return;
      }
      _DAT_800e1130 = _DAT_800e1130 | 0x80000;
      *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
      return;
    }
    if (bVar1 == 3) {
      func_0x8003331c(param_1,param_2,param_3,0);
      func_0x80036b84(param_1,0xb,0,0);
      return;
    }
    return;
  }
  if (bVar1 != 0) {
    return;
  }
  uVar4 = _DAT_800e110c | 0x100;
  uVar2 = _DAT_800e110c & 0x40000000;
  _DAT_800e110c = uVar4;
  if (uVar2 == 0) {
LAB_80162aa8:
    uVar5 = 7;
  }
  else {
    iVar3 = func_0x800837ac(0x800e8eb8,0x10);
    uVar5 = 0xe;
    if (iVar3 == 0) goto LAB_80162aa8;
  }
  func_0x80083c14(uVar5);
  DAT_800e9183 = 1;
  _DAT_800e1c60 = 0;
  _DAT_800e1136 = 0;
  *(ushort *)(param_1 + 0xad) = *(ushort *)(param_1 + 0xad) | 2;
  DAT_800e1134 = 5;
  DAT_800e1135 = 0;
  _DAT_800e1322 = 0xffff;
  param_1[10] = 0xffffa5da;
  *(undefined2 *)((int)param_1 + 0x2c6) = 0;
  *(undefined2 *)(param_1 + 0xb1) = 0;
  *(undefined1 *)(param_1 + 0xb0) = 0;
  *(ushort *)(param_1 + 0xad) = *(ushort *)(param_1 + 0xad) & 0xfffb;
  _DAT_800e1160 = 0xfffffc6d;
  _DAT_800e1158 = param_1[10] + 0x2993;
  _DAT_800e1354 = param_1[0x89];
  _DAT_800e1358 = param_1[0x8a];
  _DAT_800e1380 = param_1;
  *param_1 = *param_1 | 0x100a;
  _DAT_800e1130 = _DAT_800e1130 | 0x1008;
  DAT_800e139f = DAT_800e139f | 0x80;
  *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
LAB_80162b78:
  func_0x80036c68(param_1,4,0,0);
  if (*(char *)((int)param_1 + 0x1e9) == '\r') {
    _DAT_800e10ec = _DAT_800e10ec | 0x4000100;
    func_0x800331fc(&DAT_800e1130,param_2,param_3,0);
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
    _DAT_800e1324 = 1;
    _DAT_800e1196 = *(undefined2 *)((int)param_1 + 0x66);
  }
  return;
}
