/* FUN_80164608
 * image   ovl_008e046 (ovl), base 0x80161cf0
 * address 0x80164608  body 0x80164608..0x801648df  size 728 B
 * body sha256 3d083473e6d8a3d66bcf657174475b6eb55b1e4814309ddee412a2777c3c6a67
 * provider record sha256 55af6a2bd7a722cc6868ad16bfda4e949c87688770f82008e016f03abad31e50
 * callees 11 direct (11 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80164608(uint *param_1)

{
  uint *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  int local_38;
  int local_34;
  int local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  uVar3 = param_1[0x8d];
  func_0x800653d0(param_1,0x800e1158,0,0);
  if ((_DAT_800e1110 & 0x20000000) == 0) {
    _DAT_80167538 = 0;
    DAT_8016753c = 0;
    if ((*(byte *)((int)param_1 + 0x26f) & 0x7f) != 0) {
      *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) - 1;
    }
    if (*(char *)((int)param_1 + 0x2ca) != '\0') {
      *(char *)((int)param_1 + 0x2ca) = *(char *)((int)param_1 + 0x2ca) + -1;
    }
    (*(code *)(&PTR_FUN_80167488)[*(byte *)(param_1 + 1)])(param_1,param_1[0x69],param_1[0x86]);
    FUN_80162e10(param_1,*(undefined1 *)((int)param_1 + 0x2ce));
    if (((DAT_80167538 != 0) || (DAT_8016753a != 0)) || (DAT_8016753c != 0)) {
      func_0x800838c0(param_1 + 10,param_1 + 0x76,param_1 + 0x6e,&DAT_80167538);
      *(ushort *)(param_1 + 0x76) = *(short *)(param_1 + 0x76) + 0x40U & 0xff80;
      *(ushort *)((int)param_1 + 0x1da) = *(short *)((int)param_1 + 0x1da) + 0x40U & 0xff80;
      *(ushort *)(param_1 + 0x77) = *(short *)(param_1 + 0x77) + 0x40U & 0xff80;
      func_0x80040e58(param_1 + 0x76,param_1[0x1c]);
    }
    FUN_8016237c(param_1);
    if ((param_1[0xb2] & 0x40000) == 0) {
      func_0x80033648(param_1);
    }
    if ((code *)param_1[0xb6] != (code *)0x0) {
      (*(code *)param_1[0xb6])(param_1);
    }
    local_48 = *(undefined4 *)(uVar3 + 0x4c);
    local_44 = *(undefined4 *)(uVar3 + 0x50);
    local_40 = *(undefined4 *)(uVar3 + 0x54);
    func_0x8004da40(param_1,&local_48);
    *(undefined1 *)((int)param_1 + 0xd) = 0xff;
    puVar2 = (undefined4 *)&DAT_800e13e8;
    if (_DAT_800df93c != (undefined4 *)&DAT_800e13e8) {
      do {
        puVar1 = (uint *)*puVar2;
        if ((param_1 != puVar1) && ((*puVar1 & 1) != 0)) {
          func_0x8004d3a0(puVar1,param_1);
        }
        puVar2 = puVar2 + 1;
      } while (puVar2 != _DAT_800df93c);
    }
    func_0x80082200(&local_20,0,8);
    local_20 = CONCAT22(*(undefined2 *)((int)param_1 + 0x2d6),local_20._2_2_);
    local_28 = local_20;
    local_24 = local_1c;
    func_0x800837d0((int)*(short *)((int)param_1 + 0x66),&local_28,&local_28);
    local_38 = *(int *)(uVar3 + 0x1c4) + (int)local_28._0_2_;
    local_34 = *(int *)(uVar3 + 0x1c8) + (int)local_28._2_2_;
    local_30 = *(int *)(uVar3 + 0x1cc) + (int)local_24._0_2_;
    func_0x8004da40(param_1,&local_38);
    if ((*(ushort *)(param_1 + 0xb2) & 0x100) == 0) {
      func_0x8004dcb8(param_1,0x400);
    }
    else {
      *(ushort *)(param_1 + 0xb2) = *(ushort *)(param_1 + 0xb2) & 0xfeff;
      *(undefined2 *)(param_1 + 0x6d) = *(undefined2 *)((int)param_1 + 0x122);
      *(undefined2 *)((int)param_1 + 0x1b6) = *(undefined2 *)((int)param_1 + 0x12a);
    }
    func_0x8004da40(param_1,&local_48);
  }
  return;
}
