/* FUN_80162554
 * image   ovl_0093192 (ovl), base 0x80161cf0
 * address 0x80162554  body 0x80162554..0x801626bb  size 360 B
 * body sha256 f34ad21414006d7fe2ed56f13cea4588a7220eb15efb63e6f22a85d96358e49b
 * provider record sha256 e319ea41ef8846bb8577189360bd44f60dbb849532c5efea77050a00e409d3fa
 * callees 5 direct (5 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162554(uint *param_1)

{
  ushort uVar2;
  int iVar1;
  
  if (*(char *)((int)param_1 + 6) == '\0') {
    *(undefined1 *)((int)param_1 + 6) = 1;
    uVar2 = func_0x80033604();
    *(ushort *)(param_1 + 0x78) = (uVar2 & 0x3f) + 0x5a;
    *(undefined2 *)((int)param_1 + 0x1e2) = 0xfed4;
    *param_1 = *param_1 | 0x8000000;
    *(undefined1 *)((int)param_1 + 0x2bd) = 0;
    *(undefined1 *)((int)param_1 + 0x2be) = 1;
  }
  func_0x80032bd8(param_1,0,0);
  *(short *)((int)param_1 + 0x1e2) = *(short *)((int)param_1 + 0x1e2) + 0x28;
  iVar1 = FUN_80162a6c(param_1,0);
  if ((iVar1 == 0) && ((_DAT_800e110c & 0x10000000) != 0)) {
    FUN_80162a6c(param_1,1);
  }
  iVar1 = FUN_80162c90(param_1);
  if (iVar1 != 0) {
    *param_1 = *param_1 & 0xf7ffffff;
    *(undefined1 *)((int)param_1 + 0x2be) = 0;
    if (iVar1 < 0) {
      FUN_80162b9c(param_1,0,0x82);
      *(undefined2 *)((int)param_1 + 0x1f2) = 0xffff;
      param_1[0xb] = iVar1 + 10;
      param_1[1] = 0x3000000;
      *param_1 = *param_1 | 0x400;
    }
    else {
      *(undefined1 *)((int)param_1 + 5) = 1;
      *(undefined2 *)((int)param_1 + 6) = 0;
      uVar2 = func_0x80033604();
      *(ushort *)(param_1 + 0xae) = (uVar2 & 0x1f) + 0x1e;
      *param_1 = *param_1 & 0xfffffbff;
      param_1[0xb] = (int)*(short *)((int)param_1 + 0x25e);
    }
  }
  return;
}
