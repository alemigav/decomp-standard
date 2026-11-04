/* FUN_80164608
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x80164608  body 0x80164608..0x801647df  size 472 B
 * body sha256 bb85f0e461e2279f6c2fa4124a805078f7c4681e5cc550f7fdfabde7931f606e
 * provider record sha256 772152c956eadb58cd74e8ae0563939b04b9453d58c55acc51bdf46ff4e48e39
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80164608(uint *param_1)

{
  byte bVar1;
  short sVar2;
  undefined2 uVar3;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18 [2];
  int local_10;
  
  local_20 = 0x7d00000;
  local_1c = 0;
  func_0x800837d0((int)*(short *)((int)param_1 + 0x66),&local_20,&local_20);
  local_18[0] = param_1[10] + (int)local_20._0_2_;
  local_10 = param_1[0xc] + (int)local_1c._0_2_;
  bVar1 = *(byte *)((int)param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 != 2) {
        return;
      }
      sVar2 = *(short *)(param_1 + 0x7d);
      *(short *)(param_1 + 0x7d) = sVar2 + 1;
      if ((short)(sVar2 + 1) == 0xf) {
        param_1[1] = 0x1020000;
        *(undefined1 *)((int)param_1 + 0x1e9) = 0;
      }
      else {
        *(undefined1 *)((int)param_1 + 0x1e9) = 0;
      }
      goto LAB_801647c8;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined2 *)(param_1 + 0x7d) = 0;
    *(undefined2 *)((int)param_1 + 0x1f6) = 0;
    *param_1 = *param_1 | 10;
    _DAT_800e1130 = _DAT_800e1130 | 10;
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
  }
  sVar2 = *(short *)(param_1 + 0x7d);
  *(short *)(param_1 + 0x7d) = sVar2 + 1;
  if ((short)(sVar2 + 1) == 7) {
    *(undefined2 *)(param_1 + 0x7d) = 0;
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
  }
  if (*(short *)((int)param_1 + 0x1f6) == 0) {
    uVar3 = func_0x80036a30(&DAT_800e1158,local_18,400);
    *(undefined2 *)((int)param_1 + 0x1f6) = uVar3;
  }
  func_0x80032dbc(param_1,_DAT_800e1158,_DAT_800e1160,0x100);
  func_0x80032dbc(&DAT_800e1130,param_1[10],param_1[0xc],0x100);
  *(undefined1 *)((int)param_1 + 0x1e9) = 0;
LAB_801647c8:
  func_0x80036b84(param_1,2,0xf,0);
  return;
}
