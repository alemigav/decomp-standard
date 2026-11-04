/* FUN_80165724
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x80165724  body 0x80165724..0x80165a3f  size 796 B
 * body sha256 91b56f10ea90957608213a43488ebda5cb4c01472609d77fddfd003361627897
 * provider record sha256 812ca5a6f2f5cb4ff605f9fa9c48ddbbbd88c7764aef3fee2e0a2571da65f380
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165724(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  byte bVar5;
  uint uVar2;
  uint uVar3;
  ushort uVar4;
  char cVar6;
  undefined4 uVar7;
  byte abStack_1a8 [384];
  byte local_28 [8];
  byte local_20 [8];
  
  local_28[0] = 3;
  local_28[1] = 3;
  local_28[2] = 4;
  local_28[3] = 0xd;
  local_20[0] = 1;
  local_20[1] = 2;
  local_20[2] = 0x17;
  local_20[3] = 0x16;
  local_20[4] = 8;
  local_20[5] = 9;
  bVar5 = *(byte *)((int)param_1 + 6);
  if (bVar5 != 1) {
    if (1 < bVar5) {
      if (bVar5 == 2) {
        param_1[1] = 0x1010000;
        *(ushort *)((int)param_1 + 0x2b6) = *(ushort *)((int)param_1 + 0x2b6) & 0xfff7;
        return;
      }
      return;
    }
    if (bVar5 != 0) {
      return;
    }
    bVar5 = func_0x80033604();
    *(byte *)((int)param_1 + 0x206) = bVar5 & 1;
    uVar2 = func_0x80033604();
    param_1[0x7a] =
         (uint)local_28[(int)*(char *)((int)param_1 + 0x206) + *(char *)((int)param_1 + 0x207) * 2]
         * 0x1000000 + (uVar2 & 3) * 0x10000;
    if ((*(char *)((int)param_1 + 0x207) != '\0') && (*(char *)((int)param_1 + 0x206) != '\0')) {
      bVar5 = func_0x80033604();
      *(byte *)((int)param_1 + 0x1e9) = (bVar5 & 3) + 0x14;
    }
    *(undefined1 *)((int)param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x78) = 400;
    *(undefined2 *)(param_1 + 0x79) = 0;
    *(undefined2 *)((int)param_1 + 0x1f6) = 0;
    *(short *)(param_1 + 0x7d) = (short)*(char *)((int)param_1 + 0x207) << 0xb;
    *(ushort *)((int)param_1 + 0x2b6) = *(ushort *)((int)param_1 + 0x2b6) & 0xffef | 8;
    if ((*(char *)((int)param_1 + 0x2d5) == '\0') && (uVar2 = func_0x80033604(), (uVar2 & 1) != 0))
    {
      func_0x80077d18(0xc,param_1);
      *(undefined1 *)((int)param_1 + 0x2d5) = 0x96;
    }
  }
  func_0x80032b5c(param_1,(int)*(short *)(param_1 + 0x7d));
  sVar1 = *(short *)(param_1 + 0x78);
  *(ushort *)(param_1 + 0x78) = sVar1 - 0x1eU;
  if ((int)((uint)(ushort)(sVar1 - 0x1eU) << 0x10) < 0) {
    *(undefined2 *)(param_1 + 0x78) = 0;
    *(short *)((int)param_1 + 0x1f6) = *(short *)((int)param_1 + 0x1f6) + 1;
  }
  if (*(short *)((int)param_1 + 0x1f6) == 1) {
    uVar2 = func_0x80033604(param_1);
    uVar3 = func_0x80033604();
    if (((int)(uVar2 & 0xff) >> (uVar3 & 3) & 7U) != 0) {
      param_1[1] = 0x1050000;
      bVar5 = func_0x80033604();
      *(byte *)((int)param_1 + 0x2bf) = (bVar5 & 0xf) + 0x10;
      uVar4 = *(ushort *)((int)param_1 + 0x2b6);
      *(undefined1 *)((int)param_1 + 0x206) = *(undefined1 *)((int)param_1 + 0x207);
      *(ushort *)((int)param_1 + 0x2b6) = uVar4 & 0xfff7;
      uVar4 = uVar4 & 0xfff3;
      *(ushort *)((int)param_1 + 0x2b6) = uVar4;
      if (*(char *)((int)param_1 + 0x206) != '\0') {
        *(ushort *)((int)param_1 + 0x2b6) = uVar4 | 4;
      }
      bVar5 = local_20[*(char *)((int)param_1 + 0x206)];
      *(undefined1 *)((int)param_1 + 6) = 1;
      *(undefined1 *)((int)param_1 + 0x2be) = 0;
      *(undefined1 *)((int)param_1 + 0x207) = 0;
      *(ushort *)((int)param_1 + 0x2b6) = *(ushort *)((int)param_1 + 0x2b6) | 0x202;
      *param_1 = *param_1 & 0xf3ffffff | 0x4000000;
      *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
      *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) | 0x2000;
      param_1[0x7a] =
           (uint)bVar5 * 0x1000000 + (*(char *)((int)param_1 + 0x206) * 5 + 10) * 0x10000 + 0xf00;
      if (*(char *)((int)param_1 + 0x2d5) == '\0') {
        uVar2 = func_0x80033604();
        uVar7 = 0xd;
        if ((uVar2 & 1) != 0) {
          uVar7 = 0xc;
        }
        func_0x80077d18(uVar7,param_1);
        *(undefined1 *)((int)param_1 + 0x2d5) = 0x96;
      }
      *(undefined2 *)(param_1 + 0x7d) = 0;
      return;
    }
  }
  cVar6 = func_0x80089d54(param_1,param_2,param_3,0x100);
  *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar6;
  return;
}
