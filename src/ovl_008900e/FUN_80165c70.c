/* FUN_80165c70
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x80165c70  body 0x80165c70..0x80165fa7  size 824 B
 * body sha256 ac7cc7f4f21b1b1419c842ad8d6b3efcaa57f926bc95a9c478bd03215761c5ec
 * provider record sha256 e51b4587ca3a0d923802363cfa61178ff9a49f487b8337dd094ef5a26004600d
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165c70(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 local_18;
  undefined4 local_14;
  
  bVar1 = *(byte *)((int)param_1 + 6);
  if (bVar1 == 1) {
LAB_80165df8:
    if (0x28 < (ushort)(*(short *)((int)param_1 + 0x1f6) + 0x14U)) {
      *(short *)((int)param_1 + 0x1f6) =
           *(short *)((int)param_1 + 0x1f6) - *(short *)((int)param_1 + 0x1e2);
      param_1[0xb] = param_1[0xb] + (int)*(short *)((int)param_1 + 0x1e2);
    }
    iVar2 = func_0x8008a994(param_1,param_2,param_3,0x100);
    if (iVar2 != 0) {
      local_18 = 0x64f0000;
      local_14 = 0;
      func_0x800837d0((int)((uint)*(byte *)((int)param_1 + 0x207) << 0x1a) >> 0x10,&local_18,
                      &local_18);
      param_1[10] = param_1[10] + (int)local_18._0_2_;
      param_1[0xb] = 0;
      param_1[0xc] = param_1[0xc] + (int)local_14._0_2_;
      func_0x80036e70(param_1);
      param_1[0xaf] = 0;
      *(ushort *)((int)param_1 + 0x66) = (ushort)*(byte *)((int)param_1 + 0x206) << 10;
      *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
    }
  }
  else {
    if (bVar1 < 2) {
      if (bVar1 != 0) {
        return;
      }
      *(undefined2 *)(param_1 + 0x7d) = 0;
      *(undefined2 *)((int)param_1 + 0x1f6) = 0;
      iVar5 = (uint)*(byte *)((int)param_1 + 0x207) - (uint)*(byte *)((int)param_1 + 0x206);
      *param_1 = *param_1 | 0xc;
      *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
      iVar2 = iVar5;
      if (iVar5 < 0) {
        iVar2 = -iVar5;
      }
      if (1 < iVar2) {
        iVar5 = -(iVar5 / 3);
      }
      iVar2 = (int)*(short *)((int)param_1 + 0x25e);
      uVar3 = param_1[0xb];
      if (iVar2 + -0x903 <= (int)uVar3) {
        if ((iVar2 + -0x631 < (int)uVar3) || ((int)uVar3 < iVar2 + -0x66d)) {
          iVar2 = (uint)*(ushort *)((int)param_1 + 0x25e) -
                  (*(ushort *)((int)param_1 + 0x2e) + 0x64f);
          *(short *)((int)param_1 + 0x1f6) = (short)iVar2;
          *(short *)((int)param_1 + 0x1e2) = (short)((iVar2 * 0x10000 >> 0x10) / 0x16);
        }
        else {
          *(undefined2 *)((int)param_1 + 0x1e2) = 0;
          param_1[0xb] = (int)*(short *)((int)param_1 + 0x25e) - 0x64f;
        }
        uVar3 = 0xc000000;
        if (iVar5 < 0) {
          uVar3 = 0x1a000000;
        }
        param_1[0x7a] = uVar3 | 0xf00;
        *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + '\x01';
        goto LAB_80165df8;
      }
      param_1[0x7a] = 0x1b000f00;
      if (iVar5 < 0) {
        *(undefined2 *)((int)param_1 + 0x1f6) = 1;
      }
      *(undefined1 *)((int)param_1 + 6) = 3;
      FUN_801629c0(param_1);
    }
    else {
      if (bVar1 == 2) {
        *(undefined1 *)((int)param_1 + 0x1e9) = 0;
        func_0x80036dc4(param_1,3,3,0);
        *(undefined1 *)((int)param_1 + 0x2ce) = 4;
        *(ushort *)(param_1 + 0xb2) = *(ushort *)(param_1 + 0xb2) | 2;
        *(short *)(param_1 + 0x7d) = *(short *)(param_1 + 0x7d) + 1;
        *param_1 = *param_1 & 0xfffffff3;
        *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
        if (*(short *)(param_1 + 0x7d) < 4) {
          return;
        }
        param_1[1] = 0x10e0000;
        return;
      }
      if (bVar1 != 3) {
        return;
      }
    }
    func_0x800334c8(param_1,param_2,param_3,0);
    iVar2 = func_0x8008a994(param_1,param_2,param_3,
                            (int)*(short *)((int)param_1 + 0x1f6) << 0x10 | 0x100);
    if (iVar2 != 0) {
      *(undefined1 *)((int)param_1 + 6) = 0;
    }
    if (*(short *)((int)param_1 + 0x1f6) == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = 0x800;
    }
    func_0x80032c6c(param_1,uVar4,0);
  }
  return;
}
