/* FUN_801661ec
 * image   ovl_00ae24a (ovl), base 0x80161cf0
 * address 0x801661ec  body 0x801661ec..0x801664ff  size 788 B
 * body sha256 b032af141d27da0464454f4b93292f0c8d9c208f172c9e6a7923bacaaaac628f
 * provider record sha256 1812cca161b0546ee92a59340d341e40e252195ac2cf5c67a27e79cccd6f5e92
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801661ec(int param_1,int param_2)

{
  short sVar1;
  byte bVar9;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  uint uVar2;
  uint uVar3;
  ushort uVar8;
  undefined4 uVar10;
  int iVar11;
  undefined2 local_20;
  short local_1e;
  short local_1c;
  
  bVar9 = *(byte *)(param_1 + 0x2b5);
  if (bVar9 != 1) {
    if (1 < bVar9) {
      if (bVar9 == 2) {
        *(short *)(*(int *)(param_2 + 0x120) + 0xc) =
             *(short *)(*(int *)(param_2 + 0x120) + 0xc) + *(short *)(param_1 + 0x2b8);
        if (*(short *)(*(int *)(param_2 + 0x120) + 0xc) < 0x2711) {
          return;
        }
        *(undefined1 *)(param_1 + 0x2b5) = 3;
        bVar9 = func_0x80033604();
        *(byte *)(param_1 + 0x2b7) = (bVar9 & 0x3f) + 0x40;
        *(undefined2 *)(param_1 + 0x2b8) = 0;
        uVar8 = func_0x80033604();
        uVar4 = func_0x80033604();
        uVar5 = func_0x80033604();
        uVar6 = func_0x80033604();
        uVar7 = func_0x80033604();
        *(ushort *)(param_1 + 0x2ba) =
             (uVar8 & 0xff) + (uVar4 & 0xff) * 2 + (uVar5 & 0xff) * 4 + (uVar6 & 0xff) * 8 +
             (uVar7 & 0xff) * 0x10;
        uVar2 = func_0x80033604();
        uVar10 = 0xe;
        if ((uVar2 & 1) != 0) {
          uVar10 = 6;
        }
        func_0x80077d18(uVar10,param_1);
        iVar11 = *(int *)(param_1 + 0x234);
        local_20 = 0;
        uVar8 = func_0x80033604();
        local_1e = (uVar8 & 0xff) * -2 + 0x100;
        uVar8 = func_0x80033604();
        local_1c = (uVar8 & 0xff) * -2 + 0x100;
        uVar2 = func_0x80033604();
        iVar11 = iVar11 + 0x618;
        func_0x80037780((uVar2 & 0xff) * 4 + 0x1fa0,(int)*(short *)(param_1 + 0x66),iVar11,&local_20
                       );
        local_20 = 0;
        uVar8 = func_0x80033604();
        local_1e = (uVar8 & 0xff) * -2 + 0x100;
        uVar8 = func_0x80033604();
        local_1c = (uVar8 & 0xff) * -2 + 0x100;
        uVar2 = func_0x80033604();
        func_0x80037780((uVar2 & 0xff) * 4 + 0x1fa0 | 0x10000,(int)*(short *)(param_1 + 0x66),iVar11
                        ,&local_20);
        uVar2 = func_0x80033604();
        uVar3 = func_0x80033604();
        func_0x80052bd0((uVar2 & 3) + 2,uVar3 & 3);
        uVar2 = func_0x80033604();
        uVar3 = func_0x80033604();
        func_0x80052c6c((uVar2 & 3) + 3,0xfa,uVar3 & 3);
        return;
      }
      if (bVar9 != 3) {
        return;
      }
      *(short *)(*(int *)(param_2 + 0x120) + 0xc) =
           *(short *)(*(int *)(param_2 + 0x120) + 0xc) - *(short *)(param_1 + 0x2b8);
      if (*(short *)(*(int *)(param_2 + 0x120) + 0xc) < *(short *)(param_1 + 0x2ba)) {
        *(undefined1 *)(param_1 + 0x2b5) = 2;
        uVar8 = func_0x80033604();
        *(ushort *)(param_1 + 0x2b8) = (uVar8 & 0xff) * 4 + 0x800;
      }
      *(short *)(param_1 + 0x2b8) = *(short *)(param_1 + 0x2b8) + (short)*(char *)(param_1 + 0x2b7);
      return;
    }
    if (bVar9 != 0) {
      return;
    }
    *(undefined1 *)(param_1 + 0x2b5) = 1;
    *(undefined2 *)(param_1 + 0x2b8) = 0;
    *(undefined2 *)(param_1 + 0x2ba) = 0;
    *(undefined1 *)(param_1 + 0x2b7) = 0;
    func_0x80052bd0(0x1e,0);
    func_0x80052c6c(0x23,0xfa,0xf);
  }
  sVar1 = *(short *)(*(int *)(param_2 + 0x120) + 0x18);
  if (sVar1 != 0) {
    *(short *)(*(int *)(param_2 + 0x120) + 0x18) = sVar1 >> 1;
    *(undefined2 *)(param_1 + 0x2b8) = 0x400;
  }
  *(short *)(*(int *)(param_2 + 0x120) + 0xc) =
       *(short *)(*(int *)(param_2 + 0x120) + 0xc) - *(short *)(param_1 + 0x2b8);
  if (*(short *)(*(int *)(param_2 + 0x120) + 0xc) < -0xfd0) {
    *(undefined1 *)(param_1 + 0x2b5) = 2;
  }
  *(short *)(param_1 + 0x2b8) = *(short *)(param_1 + 0x2b8) + 0x20;
  return;
}
