/* FUN_801640e0
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x801640e0  body 0x801640e0..0x801643e3  size 772 B
 * body sha256 ac3b54775b4b0dc8da031bbd04bd984fd285114256ce07b772b5d3d7edd7f6a4
 * provider record sha256 77a8b96663f92ce825791d35f92fa02f9c891559826f79671e234ce3b773b700
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801640e0(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  ushort uVar5;
  short sVar6;
  uint *puVar7;
  
  puVar7 = *(uint **)(param_1 + 0x234);
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    puVar7 = *(uint **)(param_1 + 0x234);
    *(undefined4 *)(param_1 + 0x1e8) = 0;
    *(undefined1 *)(param_1 + 6) = 1;
    *puVar7 = *puVar7 | 1;
    uVar4 = (uint)*(byte *)(param_1 + 0x2b4);
    *(undefined2 *)(param_1 + 100) = *(undefined2 *)(&DAT_801671c8 + uVar4 * 0xc);
    *(undefined2 *)(param_1 + 0x66) = *(undefined2 *)(&DAT_801671ca + uVar4 * 0xc);
    uVar1 = *(undefined2 *)(&DAT_801671cc + uVar4 * 0xc);
    *(undefined1 *)(param_1 + 0x2b5) = 0;
    *(undefined2 *)(param_1 + 0x68) = uVar1;
    func_0x80077d18(0,param_1);
  case 1:
    func_0x80089d54(param_1,param_2,param_3,0x40);
    sVar6 = *(short *)(puVar7 + 0x49);
    *(short *)(puVar7 + 0x49) = sVar6 + 0x40;
    if (0x800 < (short)(sVar6 + 0x40)) {
      *(undefined1 *)(param_1 + 6) = 2;
      *(uint *)(param_1 + 0x1e8) = ((uint)*(byte *)(param_1 + 0x2b4) % 3 + 9) * 0x1000000 + 0x1f00;
    }
    break;
  case 2:
    func_0x80089d54(param_1,param_2,param_3,0x80);
    sVar6 = *(short *)(puVar7 + 0x49);
    *(short *)(puVar7 + 0x49) = sVar6 + 0x40;
    if ((short)(sVar6 + 0x40) < 0x1001) {
      return;
    }
    *(undefined2 *)(puVar7 + 0x49) = 0x1000;
    *(undefined1 *)(param_1 + 6) = 3;
    goto LAB_801643b4;
  case 3:
    func_0x80089d54(param_1,param_2,param_3,0x40);
    sVar6 = *(short *)(param_1 + 500) + -1;
    *(short *)(param_1 + 500) = sVar6;
    if (sVar6 != -1) {
      return;
    }
    uVar4 = func_0x80033604();
    uVar2 = func_0x80033604();
    *(uint *)(param_1 + 0x1e8) =
         ((uVar4 & 0xff) % 3 + 9) * 0x1000000 + ((uVar2 & 0xff) % 0x5a) * 0x10000 + 0x3f00;
    uVar5 = func_0x80033604();
    sVar6 = (uVar5 & 0xf) + 0x3c;
    goto LAB_801643c4;
  case 4:
    *(undefined1 *)(param_1 + 6) = 5;
    uVar4 = func_0x80033604();
    *(uint *)(param_1 + 0x1e8) = ((uVar4 & 1) + 7) * 0x1000000 + 0x1f00;
  case 5:
    iVar3 = func_0x80089d54(param_1,param_2,param_3,0x80);
    if (iVar3 != 0) {
      *(undefined1 *)(param_1 + 6) = 3;
      uVar4 = func_0x80033604();
      *(uint *)(param_1 + 0x1e8) = ((uVar4 & 0xff) % 3 + 9) * 0x1000000 + 0x3f00;
LAB_801643b4:
      uVar5 = func_0x80033604();
      sVar6 = (uVar5 & 0xf) + 0x1e;
LAB_801643c4:
      *(short *)(param_1 + 500) = sVar6;
    }
    break;
  default:
    break;
  }
  return;
}
