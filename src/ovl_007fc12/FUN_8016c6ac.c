/* FUN_8016c6ac
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x8016c6ac  body 0x8016c6ac..0x8016caf7  size 1100 B
 * body sha256 f2d0adb9e3b55003059cc41585849b2ff2d15f299822e725903505f5208f5867
 * provider record sha256 f996fdc9c67034011d5edad6ff04043831b6d5d1363f124621dc7f6911fad14c
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016c6ac(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  char cVar5;
  uint *puVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined2 local_38;
  undefined2 local_36;
  undefined2 local_34;
  byte abStack_32 [10];
  byte local_28 [16];
  
  abStack_32[2] = 6;
  abStack_32[3] = 10;
  local_28[0] = 0xfe;
  local_28[1] = 0x70;
  local_28[2] = 0xff;
  local_28[3] = 0x9c;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[6] = 0;
  local_28[7] = 200;
  local_28[8] = 0xff;
  local_28[9] = 0x9c;
  local_28[10] = 0;
  local_28[0xb] = 0;
  puVar6 = (uint *)param_1[0x94];
  *param_1 = *param_1 | 4;
  switch(*(undefined1 *)((int)param_1 + 6)) {
  case 0:
    bVar1 = abStack_32[*(byte *)((int)param_1 + 5)];
    *(undefined1 *)((int)param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x7d) = 0x800;
    param_1[0x7a] = (uint)bVar1 * 0x1000000 + 0xf00;
    func_0x80032dbc(param_1,puVar6[10],puVar6[0xc],0x800);
    if ((*(byte *)((int)param_1 + 5) & 1) != 0) {
      *(undefined2 *)(param_1 + 0x7d) = 0;
      *(short *)((int)param_1 + 0x66) = *(short *)((int)param_1 + 0x66) + 0x800;
    }
    func_0x80077adc(0x4000001,param_1 + 10);
    *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) | 0x12;
  case 1:
    *(short *)((int)param_1 + 0x66) = *(short *)((int)param_1 + 0x66) + *(short *)(param_1 + 0x7d);
    func_0x8003331c(param_1,param_2,param_3,0);
    sVar2 = *(short *)((int)param_1 + 0x66);
    sVar3 = *(short *)(param_1 + 0x7d);
    uVar7 = 0x100;
    goto LAB_8016ca70;
  case 2:
    bVar1 = abStack_32[*(byte *)((int)param_1 + 5)];
    *(undefined1 *)((int)param_1 + 6) = 3;
    param_1[0x7a] = (bVar1 + 1) * 0x1000000;
  case 3:
    if (*(char *)((int)param_1 + 0x1e9) == '\0') {
      uVar8 = param_1[0x8d];
      local_38 = *(undefined2 *)(abStack_32 + (*(byte *)((int)param_1 + 5) & 1) * 6 + 10);
      local_36 = *(undefined2 *)(abStack_32 + (*(byte *)((int)param_1 + 5) & 1) * 6 + 0xc);
      local_34 = *(undefined2 *)(abStack_32 + (*(byte *)((int)param_1 + 5) & 1) * 6 + 0xe);
      uVar4 = func_0x80033604();
      func_0x80037780(0xfd0,(int)(((uint)*(ushort *)((int)param_1 + 0x66) + (uVar4 & 0xff) * 2 +
                                  (*(byte *)((int)param_1 + 5) & 1) * 0x800 + -0x100) * 0x10000) >>
                            0x10,uVar8 + 0x4a0,&local_38);
    }
    if (*(char *)((int)param_1 + 0x1e9) == '\x03') {
      uVar8 = param_1[0x8d];
      local_38 = *(undefined2 *)(abStack_32 + (*(byte *)((int)param_1 + 5) & 1) * 6 + 10);
      local_36 = *(undefined2 *)(abStack_32 + (*(byte *)((int)param_1 + 5) & 1) * 6 + 0xc);
      local_34 = *(undefined2 *)(abStack_32 + (*(byte *)((int)param_1 + 5) & 1) * 6 + 0xe);
      uVar4 = func_0x80033604();
      func_0x80037780(0x17d0,(int)(((uint)*(ushort *)((int)param_1 + 0x66) + (uVar4 & 0xff) * 2 +
                                   (*(byte *)((int)param_1 + 5) & 1) * 0x800 + -0x100) * 0x10000) >>
                             0x10,uVar8 + 0x4a0,&local_38);
    }
    *(short *)((int)param_1 + 0x66) = *(short *)((int)param_1 + 0x66) + *(short *)(param_1 + 0x7d);
    func_0x8003331c(param_1,param_2,param_3,0);
    *(short *)((int)param_1 + 0x66) = *(short *)((int)param_1 + 0x66) - *(short *)(param_1 + 0x7d);
    func_0x80089d54(param_1,param_2,param_3,0x100);
    return;
  case 4:
    bVar1 = abStack_32[*(byte *)((int)param_1 + 5)];
    *(undefined1 *)((int)param_1 + 6) = 5;
    param_1[0x7a] = (bVar1 + 2) * 0x1000000 + 0x700;
    break;
  case 5:
  case 7:
    break;
  case 6:
    param_1[0x7a] = 0x9000000;
    *(undefined1 *)((int)param_1 + 6) = 7;
    if ((*(byte *)((int)param_1 + 5) & 1) != 0) {
      *(undefined2 *)(param_1 + 0x7d) = 0x800;
      *(short *)((int)param_1 + 0x66) = *(short *)((int)param_1 + 0x66) + 0x800;
    }
    break;
  case 8:
    param_1[1] = 0x1000000;
    DAT_800e139f = DAT_800e139f & 0x7f;
    *(byte *)(param_1 + 0x97) = *(byte *)(param_1 + 0x97) & 0xed;
    *param_1 = *param_1 & 0xffffeffb;
    *puVar6 = *puVar6 & 0xffffeffb;
  default:
    goto switchD_8016c748_default;
  }
  *(short *)((int)param_1 + 0x66) = *(short *)((int)param_1 + 0x66) + *(short *)(param_1 + 0x7d);
  func_0x8003331c(param_1,param_2,param_3,0);
  sVar2 = *(short *)((int)param_1 + 0x66);
  sVar3 = *(short *)(param_1 + 0x7d);
  uVar7 = 0x200;
LAB_8016ca70:
  *(short *)((int)param_1 + 0x66) = sVar2 - sVar3;
  cVar5 = func_0x80089d54(param_1,param_2,param_3,uVar7);
  *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar5;
switchD_8016c748_default:
  return;
}
