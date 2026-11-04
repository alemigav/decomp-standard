/* FUN_80164140
 * image   ovl_0093aba (ovl), base 0x80161cf0
 * address 0x80164140  body 0x80164140..0x8016468f  size 1360 B
 * body sha256 9c9b98b0a9d81b81b8b328b55d5815ce30fc27b26a0bd17a963e4afadca1d82b
 * provider record sha256 600cf512838d64180dc288be0e9f79e0d19257b83fedccedd3f2b57c66a576c6
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80164140(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  char cVar4;
  uint uVar2;
  ushort uVar3;
  int iVar5;
  int *piVar6;
  uint *puVar7;
  short local_20;
  short local_1e;
  short local_1c;
  
  switch(*(undefined1 *)((int)param_1 + 6)) {
  case 0:
    iVar5 = 10;
    uVar2 = param_1[0x8d];
    param_1[0x7a] = 0xc000000;
    *(undefined1 *)((int)param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x7d) = 0x1e;
    *(undefined1 *)((int)param_1 + 0x206) = 0x5a;
    do {
      *(undefined4 *)(uVar2 + 0x60) = 0xc0c0c0;
      iVar5 = iVar5 + -1;
      uVar2 = uVar2 + 0x178;
    } while (iVar5 != 0);
    func_0x80077d18(7,param_1);
  case 1:
    if (*(char *)((int)param_1 + 0x206) == '<') {
      *(uint *)(param_1[0x8d] + 0x178) = *(uint *)(param_1[0x8d] + 0x178) & 0xffffbfff;
    }
    iVar5 = *(int *)(_DAT_800e13f0 + 0x234);
    local_20 = *(short *)(param_1 + 0x7d);
    local_1e = *(short *)(param_1 + 0x7d) / 5 + 0x3c;
    uVar3 = func_0x80033604();
    local_1c = 0x40 - (uVar3 & 0x7f);
    func_0x8004276c(iVar5 + 0x618,&local_20,&local_20);
    param_1[10] = (int)local_20 + *(int *)(iVar5 + 0x62c);
    param_1[0xb] = (int)local_1e + *(int *)(iVar5 + 0x630);
    param_1[0xc] = (int)local_1c + *(int *)(iVar5 + 0x634);
    func_0x80089d54(param_1,param_2,param_3,0x100);
    cVar4 = *(char *)((int)param_1 + 0x206) + -1;
    *(char *)((int)param_1 + 0x206) = cVar4;
    *(short *)(param_1 + 0x7d) = *(short *)(param_1 + 0x7d) + 5;
    if (cVar4 == -1) {
      *(undefined1 *)((int)param_1 + 6) = 2;
    }
    break;
  case 2:
    *(undefined2 *)(param_1 + 0x7d) = 0;
    *(undefined1 *)((int)param_1 + 6) = 3;
    *(uint *)(param_1[0x8d] + 0x5e0) = *(uint *)(param_1[0x8d] + 0x5e0) & 0xffffbfff;
    *(uint *)(param_1[0x8d] + 0x758) = *(uint *)(param_1[0x8d] + 0x758) & 0xffffbfff;
    *(uint *)(param_1[0x8d] + 0x8d0) = *(uint *)(param_1[0x8d] + 0x8d0) & 0xffffbfff;
    *(uint *)(param_1[0x8d] + 0xa48) = *(uint *)(param_1[0x8d] + 0xa48) & 0xffffbfff;
    *(uint *)(param_1[0x8d] + 0xbc0) = *(uint *)(param_1[0x8d] + 0xbc0) & 0xffffbfff;
    *(uint *)(param_1[0x8d] + 0xd38) = *(uint *)(param_1[0x8d] + 0xd38) & 0xffffbfff;
    func_0x80077d18(7,param_1);
  case 3:
    func_0x80089d54(param_1,param_2,param_3,0x100);
    param_1[0xb] = param_1[0xb] + (int)*(short *)(param_1 + 0x7d);
    *(short *)(param_1 + 0x7d) = *(short *)(param_1 + 0x7d) + 0x1e;
    if ((int)*(short *)((int)param_1 + 0x25e) < (int)param_1[0xb]) {
      *(undefined1 *)((int)param_1 + 6) = 4;
      *(undefined1 *)((int)param_1 + 0x1a2) = 3;
      param_1[0xb] = (int)*(short *)((int)param_1 + 0x25e);
      *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
    }
    break;
  case 4:
    param_1[0x7a] = 0xb000300;
    uVar3 = func_0x80033604();
    *(ushort *)(param_1 + 0x7d) = (uVar3 & 0x1f) + 0x78;
    *(undefined1 *)((int)param_1 + 6) = 5;
    *(undefined2 *)((int)param_1 + 0x1f6) = 1;
    *param_1 = *param_1 | 0x4000000;
    func_0x80077d18(5,param_1);
  case 5:
    *(short *)((int)param_1 + 0x212) =
         *(short *)((int)param_1 + 0x212) + 0x12 + *(short *)((int)param_1 + 0x1f6) * 0x1e;
    *(short *)((int)param_1 + 0x1f6) = -*(short *)((int)param_1 + 0x1f6);
    if (0x1000 < *(short *)((int)param_1 + 0x212)) {
      *(undefined2 *)((int)param_1 + 0x212) = 0x1000;
    }
    if (*(short *)(param_1 + 0x7d) == 0x3c) {
      param_1[0x7a] = 0x9000300;
    }
    if (((param_1[0x7d] & 0x3f0000) != 0) && (uVar2 = func_0x80033604(), (uVar2 & 0x1f) == 0)) {
      func_0x80077d18(5,param_1);
    }
    uVar3 = func_0x80033604();
    *(ushort *)(param_1 + 0x78) = 0x10 - (uVar3 & 0x1f);
    uVar3 = func_0x80033604();
    *(ushort *)(param_1 + 0x79) = 0x10 - (uVar3 & 0x1f);
    param_1[10] = param_1[10] + (int)*(short *)(param_1 + 0x78);
    param_1[0xc] = param_1[0xc] + (int)*(short *)(param_1 + 0x79);
    uVar3 = func_0x80033604();
    *(ushort *)((int)param_1 + 0x66) = *(short *)((int)param_1 + 0x66) - ((uVar3 & 0xff) - 0x80);
    if (*(short *)(param_1 + 0x7d) < 0x5a) {
      iVar5 = 10;
      piVar6 = (int *)(param_1[0x8d] + 0x60);
      do {
        iVar5 = iVar5 + -1;
        *piVar6 = *piVar6 + -0x10101;
        piVar6 = piVar6 + 0x5e;
      } while (iVar5 != 0);
    }
    func_0x80089d54(param_1,param_2,param_3,0x400);
    sVar1 = *(short *)(param_1 + 0x7d);
    *(short *)(param_1 + 0x7d) = sVar1 + -1;
    if ((short)(sVar1 + -1) == -1) {
      param_1[1] = 0x1010000;
      *(undefined2 *)(param_1 + 0x78) = 0x50;
      *param_1 = *param_1 & 0xfffff7ff;
    }
    if ((param_1[0xa3] < 400) && ((_DAT_800e112a & 6) != 0)) {
      param_1[1] = 0x3010100;
      *(undefined1 *)((int)param_1 + 0x26e) = 0;
      *(undefined2 *)(param_1 + 0x78) = 0;
      uVar2 = func_0x80033604();
      puVar7 = param_1 + 5;
      func_0x80037780(0x81fa0,(uVar2 & 0xff) << 4,puVar7,0);
      uVar2 = func_0x80033604();
      func_0x80037780(0x817d0,(uVar2 & 0xff) << 4,puVar7,0);
      uVar2 = func_0x80033604();
      func_0x80037780(0x817d0,(uVar2 & 0xff) << 4,puVar7,0);
      uVar2 = func_0x80033604();
      param_1[0x7a] = (uVar2 & 7) * 0x10000 + 0x9000000;
      *(undefined2 *)(param_1 + 0x7d) = 0;
      func_0x80052bd0(1,0);
      func_0x80052c6c(5,0x50,0);
    }
  }
  return;
}
