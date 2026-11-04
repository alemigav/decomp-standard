/* FUN_8016aa90
 * image   ovl_007fc12 (ovl), base 0x80161cf0
 * address 0x8016aa90  body 0x8016aa90..0x8016ae0b  size 892 B
 * body sha256 1cb8f5bb44c385693c7d2aa3cfd442c9aa1f8f1809b26eb62f7bf0850f6c7bcb
 * provider record sha256 4d0a0aa504234b3e25d6112aaf8e140edd9813d385ae5d1f00321fe45ac1d220
 * callees 11 direct (11 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016aa90(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar4;
  int iVar1;
  short sVar2;
  char cVar5;
  ushort uVar3;
  uint uVar6;
  uint *puVar7;
  byte local_38 [8];
  undefined2 local_30;
  short local_2e;
  undefined2 local_2c;
  
  local_38[0] = 1;
  local_38[1] = 2;
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    bVar4 = func_0x80033604();
    *(byte *)(param_1 + 0x206) = bVar4 & 1;
    uVar3 = *(ushort *)(param_1 + 0x2b6) & 0xfffb;
    *(ushort *)(param_1 + 0x2b6) = uVar3;
    if (*(char *)(param_1 + 0x206) != '\0') {
      *(ushort *)(param_1 + 0x2b6) = uVar3 | 4;
    }
    iVar1 = *(int *)(param_1 + 0x234);
    bVar4 = local_38[*(char *)(param_1 + 0x206)];
    *(undefined1 *)(param_1 + 6) = 1;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) | 0x80;
    *(uint *)(param_1 + 0x1e8) =
         (uint)bVar4 * 0x1000000 + *(char *)(param_1 + 0x206) * 0xa0000 + 0x300;
    local_30 = *(undefined2 *)(iVar1 + 0xbde);
    local_2e = *(short *)(iVar1 + 0xbe2) + 300;
    local_2c = *(undefined2 *)(iVar1 + 0xbe6);
    iVar1 = *(int *)(param_1 + 0x234) + 0x38;
    func_0x80037780(8000,(int)*(short *)(param_1 + 0x66),iVar1,&local_30);
    sVar2 = func_0x80032d14((int)*(short *)(param_1 + 0x2a),(int)*(short *)(param_1 + 0x32),
                            (int)_DAT_800e115a,(int)_DAT_800e1162);
    local_2e = local_2e + -400;
    func_0x80037780(0x8001b58,(int)sVar2,iVar1,&local_30);
    func_0x80037780(0x21f40,(int)*(short *)(param_1 + 0x66),iVar1,&local_30);
    iVar1 = *(int *)(param_1 + 0x234);
    *(undefined1 *)(param_1 + 0x25c) = 1;
    uVar6 = *(uint *)(iVar1 + 0xbc0);
    if ((DAT_800e9012 & 8) != 0) {
      uVar6 = uVar6 | 0x4a;
    }
    *(uint *)(iVar1 + 0xbc0) = uVar6;
    *(short *)(iVar1 + 0xcf0) = sVar2 + 0x800;
    *(undefined2 *)(iVar1 + 0xcf4) = 400;
    *(undefined2 *)(iVar1 + 0xcf2) = 0xff9c;
    *(undefined2 *)(iVar1 + 0xcf6) = 10;
    *(undefined2 *)(iVar1 + 0xcf8) = 0;
    *(undefined2 *)(iVar1 + 0xcfc) = 0xffce;
    *(undefined4 *)(iVar1 + 0xc20) = 0x101040;
    func_0x80038e98(5,3,iVar1 + 0xbf8);
    puVar7 = *(uint **)(param_1 + 0x234);
    puVar7[0x4c] = 0x40;
    puVar7[0x4d] = 0x101010;
    *puVar7 = *puVar7 | 0x80;
    func_0x80077d18(2,param_1);
    func_0x80035b84(param_1);
    *(undefined2 *)(param_1 + 0x1e0) = 0xb;
    uVar6 = func_0x80033604();
    if ((uVar6 & 1) != 0) {
      *(undefined1 *)(param_1 + 6) = 3;
      return;
    }
  case 1:
    cVar5 = func_0x80089d54(param_1,param_2,param_3,0x100);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar5;
    if (*(char *)(param_1 + 0x1ea) == '\0') {
      func_0x80033680(param_1,0,1);
    }
    break;
  case 2:
    *(undefined4 *)(param_1 + 4) = 0x7000000;
    break;
  case 3:
    *(undefined1 *)(param_1 + 6) = 4;
    *(uint *)(param_1 + 0x1e8) = (uint)*(byte *)(param_1 + 0x2b4) * 0x1000000 + 0xf00;
    uVar3 = func_0x80033604();
    *(ushort *)(param_1 + 500) = (uVar3 & 0x3f) + 0x1e;
  case 4:
    sVar2 = *(short *)(param_1 + 500) + -1;
    *(short *)(param_1 + 500) = sVar2;
    if (sVar2 == -1) {
      *(undefined1 *)(param_1 + 6) = 1;
      *(undefined4 *)(param_1 + 0x1e8) = 0x1000f00;
      *(ushort *)(param_1 + 0x2b6) = *(ushort *)(param_1 + 0x2b6) & 0xfffb;
    }
    func_0x80032dbc(param_1,(int)*(short *)(param_1 + 0x260),(int)*(short *)(param_1 + 0x262),8);
    func_0x800334c8(param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218),0);
    func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x1a4),*(undefined4 *)(param_1 + 0x218),0x100)
    ;
    func_0x80032b5c(param_1,0);
  }
  return;
}
