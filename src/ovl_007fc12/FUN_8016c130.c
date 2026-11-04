/* FUN_8016c130
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x8016c130  body 0x8016c130..0x8016c6a3  size 1396 B
 * body sha256 77cdd5cadd6f0369806cf6c296b8218d3da2103d7196154da034b0ce3cff0116
 * provider record sha256 b82bafcd0fc038a20b1a622a43b3d3e0103feea34fc8d357e5ace4b01c51ef63
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016c130(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  char cVar2;
  byte bVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined2 local_40;
  undefined2 local_3e;
  undefined2 local_3c;
  byte local_38 [8];
  byte local_30 [16];
  
  local_38[1] = 3;
  local_38[0] = 0;
  local_30[0] = 0;
  local_30[1] = 0;
  local_30[2] = 0;
  local_30[3] = 200;
  local_30[4] = 0;
  local_30[5] = 100;
  local_30[6] = 0xff;
  local_30[7] = 0x9c;
  local_30[8] = 0;
  local_30[9] = 100;
  local_30[10] = 0xff;
  local_30[0xb] = 0x38;
  puVar4 = (uint *)param_1[0x94];
  switch(*(undefined1 *)((int)param_1 + 6)) {
  case 0:
    bVar3 = local_38[*(byte *)((int)param_1 + 5)];
    *(undefined1 *)((int)param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x7d) = 0x800;
    *(undefined1 *)((int)param_1 + 0x206) = 0;
    param_1[0x7a] = (uint)bVar3 * 0x1000000 + 0xf00;
    func_0x80032dbc(param_1,puVar4[10],puVar4[0xc],0x800);
    if ((*(byte *)((int)param_1 + 5) & 1) != 0) {
      *(undefined2 *)(param_1 + 0x7d) = 0;
      *(short *)((int)param_1 + 0x66) = *(short *)((int)param_1 + 0x66) + 0x800;
    }
    DAT_8016e870 = 0xff;
    DAT_8016e871 = 0xff;
    DAT_8016e872 = 0xff;
    DAT_8016e873 = 0xff;
    DAT_8016e874 = 0;
    uVar8 = func_0x80033604();
    func_0x80077adc((uVar8 & 1) << 0x11 | 0x4000001,param_1 + 10);
    *(undefined2 *)((int)param_1 + 0x1f6) = 0;
    *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) | 0x12;
  case 1:
    *(short *)((int)param_1 + 0x66) = *(short *)((int)param_1 + 0x66) + *(short *)(param_1 + 0x7d);
    func_0x8003331c(param_1,param_2,param_3,0);
    *(short *)((int)param_1 + 0x66) = *(short *)((int)param_1 + 0x66) - *(short *)(param_1 + 0x7d);
    cVar2 = func_0x80089d54(param_1,param_2,param_3,0x100);
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar2;
    break;
  case 2:
    bVar3 = local_38[*(byte *)((int)param_1 + 5)];
    *(undefined1 *)((int)param_1 + 6) = 3;
    param_1[0x7a] = (bVar3 + 1) * 0x1000000;
  case 3:
    if (*(char *)((int)param_1 + 0x1e9) == '\x0f') {
      uVar5 = param_1[0x8d];
      local_40 = *(undefined2 *)(local_38 + (*(byte *)((int)param_1 + 5) & 1) * 6 + 8);
      local_3e = *(undefined2 *)(local_38 + (*(byte *)((int)param_1 + 5) & 1) * 6 + 10);
      local_3c = *(undefined2 *)(local_38 + (*(byte *)((int)param_1 + 5) & 1) * 6 + 0xc);
      uVar8 = func_0x80033604();
      func_0x80037780(0x17d0,(int)(((uint)*(ushort *)((int)param_1 + 0x66) + (uVar8 & 0xff) * 2 +
                                   (*(byte *)((int)param_1 + 5) & 1) * 0x800 + -0x100) * 0x10000) >>
                             0x10,uVar5 + 0xbf8,&local_40);
      *(undefined1 *)((int)param_1 + 0x206) = 0;
    }
    *(short *)((int)param_1 + 0x66) = *(short *)((int)param_1 + 0x66) + *(short *)(param_1 + 0x7d);
    func_0x8003331c(param_1,param_2,param_3,0);
    *(short *)((int)param_1 + 0x66) = *(short *)((int)param_1 + 0x66) - *(short *)(param_1 + 0x7d);
    func_0x80089d54(param_1,param_2,param_3,0x100);
    break;
  case 4:
    bVar3 = local_38[*(byte *)((int)param_1 + 5)];
    *(undefined1 *)((int)param_1 + 6) = 5;
    param_1[0x7a] = (bVar3 + 2) * 0x1000000 + 0x700;
    if (*(char *)((int)param_1 + 0x206) != '\0') {
      uVar5 = param_1[0x8d];
      local_40 = *(undefined2 *)(local_38 + (*(byte *)((int)param_1 + 5) & 1) * 6 + 8);
      local_3e = *(undefined2 *)(local_38 + (*(byte *)((int)param_1 + 5) & 1) * 6 + 10);
      local_3c = *(undefined2 *)(local_38 + (*(byte *)((int)param_1 + 5) & 1) * 6 + 0xc);
      uVar8 = func_0x80033604();
      func_0x80037780(0x17d0,(int)(((uint)*(ushort *)((int)param_1 + 0x66) + (uVar8 & 0xff) * 2 +
                                   (*(byte *)((int)param_1 + 5) & 1) * 0x800 + -0x100) * 0x10000) >>
                             0x10,uVar5 + 0xbf8,&local_40);
    }
  case 5:
    *(short *)((int)param_1 + 0x66) = *(short *)((int)param_1 + 0x66) + *(short *)(param_1 + 0x7d);
    func_0x8003331c(param_1,param_2,param_3,0);
    *(short *)((int)param_1 + 0x66) = *(short *)((int)param_1 + 0x66) - *(short *)(param_1 + 0x7d);
    cVar2 = func_0x80089d54(param_1,param_2,param_3,0x200);
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar2;
    if (*(byte *)((int)param_1 + 0x1e9) - 9 < 5) {
      uVar8 = 2;
      if ((*(ushort *)((int)param_1 + 0xe) & 0x3fff) != 0) {
        iVar7 = -0x7ff38948;
        uVar5 = (uint)*(ushort *)((int)param_1 + 0xe) << 2;
        do {
          if ((((((uVar5 & 0x8000) != 0) &&
                (((int)*(short *)((int)param_1 + 0x1f6) >> (uVar8 & 0x1f) & 1U) == 0)) &&
               (iVar6 = *(int *)(iVar7 + 0x19d38), (*(byte *)(iVar6 + 8) & 0x10) != 0)) &&
              ((-1 < *(short *)(iVar6 + 0x1f2) && ((*(ushort *)(iVar6 + 0x1aa) & 1) == 0)))) &&
             ((*(char *)(iVar6 + 0x26f) == '\0' &&
              (((*(ushort *)(iVar6 + 0x2b6) & 8) == 0 &&
               ((*(ushort *)(iVar6 + 0x1aa) & 0x2000) == 0)))))) {
            *(undefined4 *)(iVar6 + 4) = 0x1090000;
            bVar3 = func_0x80033160(param_1,iVar6);
            *(byte *)(iVar6 + 0x207) = ~bVar3 & 1;
          }
          iVar7 = iVar7 + 4;
          uVar1 = uVar5 & 0x7fff;
          uVar8 = uVar8 + 1;
          uVar5 = uVar5 << 1;
        } while (uVar1 != 0);
      }
      *(ushort *)((int)param_1 + 0x1f6) =
           *(ushort *)((int)param_1 + 0x1f6) | *(ushort *)((int)param_1 + 0xe);
    }
    break;
  case 6:
    param_1[1] = 0x1000000;
    DAT_800e139f = DAT_800e139f & 0x7f;
    *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) & 0xed;
    *param_1 = *param_1 & 0xffffeffb;
    *puVar4 = *puVar4 & 0xffffeffb;
  }
  return;
}
