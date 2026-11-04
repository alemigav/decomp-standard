/* FUN_801636a0
 * image   ovl_00ae24a (ovl), base 0x80161cf0
 * address 0x801636a0  body 0x801636a0..0x80163923  size 644 B
 * body sha256 ccf889c896e7e3d389e88e260a1fef27a1505402ceb4d12b237f642f2ee53670
 * provider record sha256 778925bd7628b84d356c8373e70f22141916a8d04697a6b4a01981bd53ec69dd
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_801636a0(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  ushort uVar5;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar6;
  short local_20;
  short local_1e;
  short local_1c;
  
  bVar1 = *(byte *)((int)param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        param_1[0x7a] = 0x2000700;
        *(undefined1 *)((int)param_1 + 6) = 3;
        func_0x80077d18(10,param_1);
        *(undefined2 *)((int)param_1 + 0x1f6) = 0x96;
      }
      else if (bVar1 != 3) {
        return;
      }
      func_0x80089d54(param_1,param_2,param_3,0x200);
      if (*(short *)((int)param_1 + 0x1f6) != 0) {
        *(short *)((int)param_1 + 0x1f6) = *(short *)((int)param_1 + 0x1f6) + -1;
      }
      if (*(short *)((int)param_1 + 0x1f6) != 0) {
        return;
      }
      if (*(short *)(*(int *)(param_1[0x8d] + 0x410) + 0xc) < 6000) {
        *(undefined1 *)(param_1 + 0xad) = 0;
        *(undefined1 *)((int)param_1 + 0x2b5) = 0;
        return;
      }
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    param_1[0x7a] = 0x9000700;
    *(undefined1 *)((int)param_1 + 6) = 1;
    _DAT_800e1380 = param_1;
    func_0x800331fc(&DAT_800e1130,param_2,param_3,0);
    _DAT_800e1354 = param_1[0x89];
    _DAT_800e1134 = 0x6000000;
    _DAT_800e1358 = param_1[0x8a];
    DAT_800e139f = DAT_800e139f | 0x80;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
    *param_1 = *param_1 | 0x1000;
    _DAT_800e1130 = _DAT_800e1130 | 0x1002;
    _DAT_800e1326 = *(short *)((int)param_1 + 0x66) + 0x800;
    func_0x80077d18(6,param_1);
  }
  if (*(char *)((int)param_1 + 0x1e9) == '\n') {
    func_0x80077d18(7,param_1);
  }
  if (*(byte *)((int)param_1 + 0x1e9) - 0x10 < 0xe) {
    uVar6 = param_1[0x8d];
    uVar5 = func_0x80033604(param_1);
    local_20 = (uVar5 & 0xff) * -2 + 0x100;
    uVar5 = func_0x80033604();
    local_1e = (uVar5 & 0xff) * -2 + 0x100;
    uVar5 = func_0x80033604();
    local_1c = (uVar5 & 0xff) * -2 + 0x100;
    uVar2 = func_0x80033604();
    uVar3 = func_0x80033604();
    func_0x80037780((uVar2 & 1) << 0x10 | (uVar3 & 0xff) * 8 + 0x17d0,
                    (int)*(short *)((int)param_1 + 0x66),uVar6 + 0x618,&local_20);
  }
  func_0x8003331c(param_1,param_2,param_3,0);
  iVar4 = func_0x80089d54(param_1,param_2,param_3,0x200);
  if (iVar4 != 0) {
    *(undefined1 *)((int)param_1 + 6) = 2;
  }
  return;
}
