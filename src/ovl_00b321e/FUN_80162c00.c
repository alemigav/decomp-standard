/* FUN_80162c00
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80162c00  body 0x80162c00..0x80162ddf  size 480 B
 * body sha256 cb3de3790aa07dda1e1acd36881b01c8df26c035a8f52c50de57189bb95a6ec7
 * provider record sha256 6ae5d7e289103266ad11b279de641330533fa78f302ef8691997229f7d21877d
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162c00(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  
  bVar1 = *(byte *)((int)param_1 + 7);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 != 2) {
        return;
      }
      sVar2 = *(short *)(param_1 + 0x7d);
      *(short *)(param_1 + 0x7d) = sVar2 + -1;
      if (sVar2 == 1) {
        *(undefined1 *)((int)param_1 + 5) = 1;
        *(undefined2 *)((int)param_1 + 6) = 0;
        *(undefined1 *)(param_1 + 0xb2) = 0x3c;
      }
      goto LAB_80162dbc;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined2 *)(param_1 + 0x78) = 0xff9c;
    *(undefined2 *)((int)param_1 + 0x1e2) = 0x28;
    *(undefined1 *)((int)param_1 + 7) = 1;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
    *(undefined2 *)(param_1 + 0x7d) = *(undefined2 *)((int)param_1 + 0x66);
    func_0x80033604();
    *(undefined1 *)((int)param_1 + 0x206) = 0x80;
    param_1[0x7a] = 0x4000f00;
  }
  if (*(short *)((int)param_1 + 0x1e2) < 500) {
    *(short *)((int)param_1 + 0x1e2) = *(short *)((int)param_1 + 0x1e2) + 0x28;
  }
  iVar3 = (uint)*(ushort *)((int)param_1 + 0x66) + (int)*(char *)((int)param_1 + 0x206);
  *(short *)((int)param_1 + 0x66) = (short)iVar3;
  func_0x80032bd8(param_1,(int)*(short *)(param_1 + 0x7d) - (iVar3 * 0x10000 >> 0x10),0);
  if ((-1 < *(short *)((int)param_1 + 0x1e2)) &&
     ((int)*(short *)((int)param_1 + 0x25e) <= (int)(param_1[0xb] + 0x30f))) {
    param_1[0xb] = (int)*(short *)((int)param_1 + 0x25e);
    *(undefined1 *)(param_1 + 0xaf) = 0;
    *param_1 = *param_1 & 0xfffffffd;
    func_0x80077d18(7,param_1);
    _DAT_800e1128 = _DAT_800e1128 & 0xffdf;
    if ((*(byte *)((int)param_1 + 0x2bd) & 1) == 0) {
      *(undefined1 *)((int)param_1 + 7) = 2;
      *(undefined2 *)(param_1 + 0x7d) = 0x1e;
      param_1[0x7a] = 0;
    }
    else {
      *(undefined1 *)((int)param_1 + 5) = 1;
      *(undefined1 *)(param_1 + 0xb2) = 0x78;
      *(undefined2 *)((int)param_1 + 6) = 0;
      param_1[0x7a] = 0x4000000;
    }
  }
LAB_80162dbc:
  func_0x80089d54(param_1,param_2,param_3,0x100);
  return;
}
