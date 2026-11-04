/* FUN_801671ec
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x801671ec  body 0x801671ec..0x8016732f  size 324 B
 * body sha256 401c3e563e4313f7d473d15b7d743a3203a973b4f6dcc458a443a1fef147555d
 * provider record sha256 f1057ce410ea65c4c39daad454fda07358896c80a72fd824d41fccfaf9a844e6
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801671ec(int param_1,uint param_2,short param_3)

{
  int iVar1;
  int iVar2;
  short local_48;
  short local_46;
  short local_44;
  undefined2 local_40;
  undefined2 local_3e;
  undefined2 local_3c;
  undefined1 auStack_38 [32];
  
  iVar2 = *(int *)(param_1 + 0x234);
  func_0x80069f1c(param_1 + 0x28,100,0x400,0);
  if ((param_2 & 0x80) == 0) {
    iVar1 = iVar2 + 0x38;
    local_48 = 1000;
    local_44 = -100;
    local_46 = 0;
  }
  else {
    local_48 = *(short *)(param_1 + 100);
    local_46 = *(short *)(param_1 + 0x66);
    local_44 = *(short *)(param_1 + 0x68);
    func_0x80040e58(&local_48,auStack_38);
    local_40 = 1000;
    local_3e = 0;
    local_3c = 0xff9c;
    func_0x8004276c(auStack_38,&local_40,&local_48);
    param_2 = param_2 & 0x7f;
    local_48 = local_48 + *(short *)(iVar2 + 0x4e);
    iVar1 = -0x7ff16fd8;
    local_46 = local_46 + *(short *)(iVar2 + 0x52);
    local_44 = local_44 + *(short *)(iVar2 + 0x56);
  }
  func_0x80037780(param_2 << 0x10 | 0x1d001000,(int)param_3,iVar1,&local_48);
  return;
}
