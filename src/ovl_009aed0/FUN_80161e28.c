/* FUN_80161e28
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x80161e28  body 0x80161e28..0x8016213f  size 792 B
 * body sha256 febf7f840d958cf9c63674a9dcc5e67131b27505d766530aa7bfd925f9b85221
 * provider record sha256 58ba8c3db0564eed0448cfac2e77f8c0349b66f4afbb2052e2d3d4efe62b64b7
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80161e28(int param_1)

{
  int iVar1;
  uint uVar2;
  ushort uVar3;
  int iVar4;
  ushort *puVar5;
  uint uVar6;
  ushort local_28 [2];
  short local_24;
  
  uVar6 = 0;
  puVar5 = &DAT_801662e0;
  do {
    iVar1 = (int)(short)(puVar5[5] + 1);
    iVar4 = *(int *)(param_1 + 0x234);
    puVar5[5] = puVar5[5] + 1;
    puVar5[4] = puVar5[4] +
                ((short)((iVar1 * iVar1 * 0x62) / 0x14) -
                (short)(((iVar1 + -1) * (iVar1 + -1) * 0x62) / 0x14));
    iVar4 = iVar4 + (uint)*puVar5 * 0x178;
    if (-1 < *(int *)(iVar4 + 0x50)) {
      puVar5[2] = (short)puVar5[2] / 0x14;
      puVar5[4] = -((short)puVar5[4] / 0x1c);
      *(undefined4 *)(iVar4 + 0x50) = 0;
      puVar5[5] = 0;
      uVar2 = *(ushort *)(iVar4 + 0x5c) & 0xfff;
      *(short *)(iVar4 + 0x5c) = (short)uVar2;
      if (uVar2 - 0x400 < 0x800) {
        if (uVar2 < 0x801) goto LAB_80161fbc;
        puVar5[7] = 10;
      }
      else if (uVar2 < 0x400) {
        puVar5[7] = 10;
      }
      else {
LAB_80161fbc:
        puVar5[7] = 0xfff6;
      }
    }
    *(ushort *)(iVar4 + 0x5c) = *(short *)(iVar4 + 0x5c) + puVar5[6];
    puVar5[6] = puVar5[6] + puVar5[7];
    uVar2 = *(ushort *)(iVar4 + 0x5c) & 0xfff;
    *(short *)(iVar4 + 0x5c) = (short)uVar2;
    uVar3 = (ushort)(uVar2 - 0x400 < 0x800);
    if (puVar5[7] == 0) {
      puVar5[8] = uVar3;
    }
    else if (uVar3 != puVar5[8]) {
      puVar5[6] = -((short)puVar5[6] / 0x14);
    }
    if ((short)puVar5[6] < 10) {
      if ((0x3f6 < *(short *)(iVar4 + 0x5c)) && (*(short *)(iVar4 + 0x5c) < 0x40a)) {
        puVar5[6] = 0;
        puVar5[7] = 0;
      }
      if ((((short)puVar5[6] < 10) && (0xbf6 < *(short *)(iVar4 + 0x5c))) &&
         (*(short *)(iVar4 + 0x5c) < 0xc0a)) {
        puVar5[6] = 0;
        puVar5[7] = 0;
      }
    }
    local_28[0] = puVar5[2];
    local_24 = 0;
    func_0x800837d0((int)(((uint)*(ushort *)(param_1 + 0x66) + (uint)puVar5[1]) * 0x10000) >> 0x10,
                    local_28,local_28);
    *(int *)(iVar4 + 0x4c) = *(int *)(iVar4 + 0x4c) + (int)(short)local_28[0];
    *(int *)(iVar4 + 0x50) = *(int *)(iVar4 + 0x50) + (int)(short)puVar5[4];
    *(int *)(iVar4 + 0x54) = *(int *)(iVar4 + 0x54) + (int)local_24;
    func_0x80040e58(iVar4 + 0x58,iVar4 + 0x38);
    uVar6 = uVar6 + 1;
    puVar5[2] = puVar5[2] + puVar5[3];
    puVar5 = puVar5 + 10;
    if (0xe < uVar6) {
      return;
    }
  } while( true );
}
