/* FUN_80161e44
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x80161e44  body 0x80161e44..0x80161fff  size 444 B
 * body sha256 4a098f1f0afa671ac0767c36ef8be52aa1218706490f3193c5ce6fb7f3c1c4b6
 * provider record sha256 f5bfc26e71d79095fce68569a8dc772bd89a1fa4bbe325e997b03e3055580fd8
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80161e44(uint *param_1)

{
  int iVar1;
  short sVar2;
  byte unaff_s0;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  uint local_1c;
  undefined4 local_18;
  
  local_28 = 0x8a20000;
  local_24 = 0;
  if (_DAT_800e1068 != 0) {
    local_20 = param_1[10];
    param_1[0xaf] = _DAT_800e1068;
    local_1c = param_1[0xb];
    local_18 = param_1[0xc];
    func_0x8006a8f4(param_1 + 10,param_1[0xaf],param_1[0x1c],&local_20);
    iVar1 = func_0x8006a4d0(param_1 + 10,param_1[0xaf],param_1[0x1c],0);
    unaff_s0 = (byte)iVar1;
    func_0x800837d0((iVar1 << 0x1a) >> 0x10,&local_28,&local_28);
    *(short *)(param_1 + 0xb4) = local_20._2_2_ + local_28._0_2_;
    *(ushort *)(param_1 + 0xb2) = *(ushort *)(param_1 + 0xb2) & 0xffef | 0x20;
    *(short *)(param_1 + 0xb5) = local_18._2_2_ + local_24._0_2_;
    goto LAB_80161fd4;
  }
  *(undefined2 *)(param_1 + 0xb4) = *(undefined2 *)((int)param_1 + 0x2a);
  *(undefined2 *)(param_1 + 0xb5) = *(undefined2 *)((int)param_1 + 0x32);
  iVar1 = func_0x8006a75c(param_1[0x1c]);
  if (iVar1 == 1) {
    sVar2 = *(short *)((int)param_1 + 0x2d2);
    unaff_s0 = 1;
    if ((int)param_1[0xb] < (int)*(short *)((int)param_1 + 0x2d2)) {
      sVar2 = sVar2 + -0x898;
    }
    else {
      unaff_s0 = 3;
LAB_80161fbc:
      sVar2 = sVar2 + 0x898;
    }
LAB_80161fc0:
    *(short *)((int)param_1 + 0x2d2) = sVar2;
  }
  else if (iVar1 == 2) {
    sVar2 = *(short *)((int)param_1 + 0x2d2);
    unaff_s0 = 2;
    if ((int)*(short *)((int)param_1 + 0x2d2) <= (int)param_1[0xb]) {
      unaff_s0 = 0;
      goto LAB_80161fbc;
    }
    sVar2 = sVar2 + -0x898;
    goto LAB_80161fc0;
  }
  *(ushort *)(param_1 + 0xb2) = *(ushort *)(param_1 + 0xb2) & 0xffdf | 0x10;
LAB_80161fd4:
  *(byte *)(param_1 + 0xad) = unaff_s0 ^ 2;
  *param_1 = *param_1 | 8;
  return;
}
