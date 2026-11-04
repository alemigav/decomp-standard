/* FUN_80164ac4
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x80164ac4  body 0x80164ac4..0x80165097  size 1492 B
 * body sha256 a4324242b6436730234cabdad1d3911cc979af29db262382ad49b21c1877f9b3
 * provider record sha256 292a705e258ec55fc133522ee984bb1d06d9238dde6dd53be133937f536c6ded
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80164ac4(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar7;
  uint uVar1;
  ushort uVar4;
  char cVar8;
  ushort uVar5;
  short sVar6;
  uint uVar2;
  int iVar3;
  undefined4 uVar9;
  byte local_48 [8];
  undefined2 local_40;
  undefined2 local_3e;
  undefined2 local_3c;
  ushort local_38 [16];
  
  local_48[0] = 1;
  local_48[1] = 2;
  local_48[2] = 0x17;
  local_48[3] = 0x16;
  local_48[4] = 8;
  local_48[5] = 9;
  local_38[0] = 0x5a;
  local_38[1] = 0x1e;
  local_38[2] = 0xaa;
  local_38[3] = 0xa0;
  local_38[4] = 10;
  local_38[5] = 0x28;
  local_38[6] = 100;
  local_38[7] = 0x32;
  local_38[8] = 0x6e;
  local_38[9] = 0x14;
  local_38[10] = 0x23;
  local_38[0xb] = 0x46;
  local_38[0xc] = 0x1e;
  local_38[0xd] = 0xb4;
  local_38[0xe] = 0x1e;
  local_38[0xf] = 0x3c;
  switch(*(undefined1 *)((int)param_1 + 6)) {
  case 0:
    bVar7 = func_0x80033604();
    *(byte *)((int)param_1 + 0x206) = bVar7 & 1;
    uVar5 = *(ushort *)((int)param_1 + 0x2b6) & 0xfffb;
    *(ushort *)((int)param_1 + 0x2b6) = uVar5;
    if (*(char *)((int)param_1 + 0x206) != '\0') {
      *(ushort *)((int)param_1 + 0x2b6) = uVar5 | 4;
    }
    bVar7 = local_48[*(char *)((int)param_1 + 0x206)];
    *(undefined1 *)((int)param_1 + 6) = 1;
    *(undefined1 *)((int)param_1 + 0x2be) = 0;
    *(undefined1 *)((int)param_1 + 0x207) = 0;
    *(ushort *)((int)param_1 + 0x2b6) = *(ushort *)((int)param_1 + 0x2b6) | 0x202;
    *param_1 = *param_1 & 0xf3ffffff | 0x4000000;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
    *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) | 0x2000;
    param_1[0x7a] =
         (uint)bVar7 * 0x1000000 + (*(char *)((int)param_1 + 0x206) * 5 + 10) * 0x10000 + 0xf00;
    if (*(char *)((int)param_1 + 0x2d5) == '\0') {
      uVar2 = func_0x80033604();
      uVar9 = 0xd;
      if ((uVar2 & 1) != 0) {
        uVar9 = 0xc;
      }
      func_0x80077d18(uVar9,param_1);
      *(undefined1 *)((int)param_1 + 0x2d5) = 0x96;
    }
    *(undefined2 *)(param_1 + 0x7d) = 0;
    *(undefined2 *)(param_1 + 0x78) = 0xb;
  case 1:
    cVar8 = func_0x80089d54(param_1,param_2,param_3,0x100);
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar8;
    if (0x14 < *(ushort *)((int)param_1 + 0x136)) {
      *(ushort *)((int)param_1 + 0x136) = *(ushort *)((int)param_1 + 0x136) - 10;
      *(short *)(param_1 + 0x4e) = *(short *)(param_1 + 0x4e) + -10;
      if (200 < *(ushort *)(param_1 + 0x4b)) {
        *(ushort *)(param_1 + 0x4b) = *(ushort *)(param_1 + 0x4b) - 10;
        *(short *)((int)param_1 + 0x12e) = *(short *)((int)param_1 + 0x12e) + -10;
      }
    }
    if ((*(char *)((int)param_1 + 0x1ea) == '\0') || (*(short *)(param_1 + 0x7d) != 0)) {
      func_0x80033680(param_1,0,1);
    }
    break;
  case 2:
    *(undefined1 *)((int)param_1 + 6) = 3;
    param_1[0x7a] = (uint)local_48[*(char *)((int)param_1 + 0x206) + 2] * 0x1000000 + 0xf00;
    uVar2 = func_0x80033604();
    uVar1 = func_0x80033604();
    uVar4 = func_0x80033604();
    uVar5 = local_38[(int)(uVar2 & 0xff) >> (uVar1 & 3) & 0xf];
    *(undefined2 *)(param_1 + 0x4b) = 200;
    *(undefined2 *)((int)param_1 + 0x12e) = 200;
    *(undefined2 *)(param_1 + 0x4d) = 0xfea2;
    *(undefined2 *)((int)param_1 + 0x13a) = 0x15e;
    *(undefined2 *)((int)param_1 + 0x136) = 0;
    *(undefined2 *)(param_1 + 0x4e) = 0;
    *(ushort *)((int)param_1 + 0x1f6) = uVar5 + (uVar4 & 0xf);
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
    uVar5 = func_0x80033604();
    *(ushort *)(param_1 + 0x78) = uVar5 & 3;
    if ((*(ushort *)((int)param_1 + 0x1aa) & 0x80) != 0) {
      *(undefined2 *)(param_1 + 0x78) = 0;
      uVar2 = func_0x80033604();
      uVar1 = func_0x80033604();
      *(ushort *)((int)param_1 + 0x1f6) = local_38[(int)(uVar2 & 0xff) >> (uVar1 & 3) & 0xf] >> 1;
    }
  case 3:
    if (*(short *)(param_1 + 0x78) == 0) {
      cVar8 = func_0x80089d54(param_1,param_2,param_3,0x100);
      *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar8;
    }
    sVar6 = *(short *)((int)param_1 + 0x1f6);
    goto LAB_80164e88;
  case 4:
    uVar5 = func_0x80033604();
    *(ushort *)(param_1 + 0x7d) = (uVar5 & 0xf) + 3;
    *(undefined1 *)((int)param_1 + 6) = 5;
  case 5:
    sVar6 = *(short *)(param_1 + 0x7d);
    *(short *)(param_1 + 0x7d) = sVar6 + -1;
    if ((short)(sVar6 + -1) == -1) {
      *(undefined1 *)((int)param_1 + 6) = 3;
    }
    sVar6 = *(short *)((int)param_1 + 0x1f6);
LAB_80164e88:
    *(short *)((int)param_1 + 0x1f6) = sVar6 + -1;
    if ((short)(sVar6 + -1) == -1) {
      *(undefined1 *)((int)param_1 + 6) = 6;
    }
    break;
  case 6:
    bVar7 = local_48[*(char *)((int)param_1 + 0x206) + 4];
    *(undefined1 *)((int)param_1 + 6) = 7;
    *(ushort *)((int)param_1 + 0x2b6) = *(ushort *)((int)param_1 + 0x2b6) | 0x10;
    *(undefined1 *)(param_1 + 0xb4) = 1;
    param_1[0x7a] = (uint)bVar7 * 0x1000000 + 0xf00;
    if ((*(ushort *)((int)param_1 + 0x2b6) & 4) != 0) {
      *(undefined1 *)(param_1 + 0xb4) = 0;
    }
    if (*(char *)((int)param_1 + 0x207) == '\x01') {
      local_40 = 0;
      local_3e = 0;
      local_3c = 0;
      func_0x80037780(8000,(int)*(short *)((int)param_1 + 0x66),param_1[0x8d] + 0x38,&local_40);
    }
    if ((*(char *)((int)param_1 + 0x2d5) == '\0') && (uVar2 = func_0x80033604(), (uVar2 & 3) == 0))
    {
      func_0x80077d18(0xb,param_1);
      *(undefined1 *)((int)param_1 + 0x2d5) = 0x96;
    }
    *(undefined2 *)(param_1 + 0x78) = 0xb;
    *(ushort *)((int)param_1 + 0x2b6) = *(ushort *)((int)param_1 + 0x2b6) & 0xfdff;
  case 7:
    if (*(ushort *)((int)param_1 + 0x136) < 500) {
      *(ushort *)((int)param_1 + 0x136) = *(ushort *)((int)param_1 + 0x136) + 10;
      *(short *)(param_1 + 0x4e) = *(short *)(param_1 + 0x4e) + 10;
      if (*(ushort *)(param_1 + 0x4b) < 500) {
        *(ushort *)(param_1 + 0x4b) = *(ushort *)(param_1 + 0x4b) + 10;
        *(short *)((int)param_1 + 0x12e) = *(short *)((int)param_1 + 0x12e) + 10;
      }
    }
    if (-0x5dc < *(short *)(param_1 + 0x4d)) {
      *(short *)(param_1 + 0x4d) = *(short *)(param_1 + 0x4d) + -10;
      *(short *)((int)param_1 + 0x13a) = *(short *)((int)param_1 + 0x13a) + 10;
    }
    iVar3 = func_0x80089d54(param_1,param_2,param_3,0x100);
    if (iVar3 != 0) {
      uVar5 = *(ushort *)((int)param_1 + 0x2b6);
      *(undefined1 *)((int)param_1 + 6) = 8;
      *(ushort *)((int)param_1 + 0x2b6) = uVar5 & 0xffef;
      *(ushort *)((int)param_1 + 0x2b6) = uVar5 & 0xffed;
    }
    if (*(char *)((int)param_1 + 0x1e9) == '7') {
      *param_1 = *param_1 | 0xc000000;
    }
    break;
  case 8:
    param_1[1] = 0x1010000;
    *(undefined2 *)((int)param_1 + 0x136) = 500;
    *(undefined2 *)(param_1 + 0x4e) = 500;
    *(undefined2 *)(param_1 + 0x4b) = 500;
    *(undefined2 *)((int)param_1 + 0x12e) = 500;
    *(undefined2 *)(param_1 + 0x4d) = 0xfa24;
    *(undefined2 *)((int)param_1 + 0x13a) = 0x5dc;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
    *param_1 = *param_1 | 0xc000000;
    *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) & 0xdfff;
    *(ushort *)((int)param_1 + 0x2b6) = *(ushort *)((int)param_1 + 0x2b6) & 0xffed;
  }
  return;
}
