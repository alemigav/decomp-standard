/* FUN_80161e1c
 * image   ovl_009d282 (ovl), base 0x80161cf0
 * address 0x80161e1c  body 0x80161e1c..0x80161ebf  size 164 B
 * body sha256 a448b159bc7ce094ea651e0d3c4cb943735f38b499737a28f7546ba3938104be
 * provider record sha256 53107720b3239e5b67b47e549477ca4dfe4156d3fff2bcafc17518963d6e2a7c
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80161e1c(int param_1)

{
  int iVar1;
  undefined2 local_10;
  undefined2 local_e;
  undefined2 local_c;
  
  iVar1 = *(int *)(param_1 + 0x234);
  local_10 = 0;
  local_e = 0;
  local_c = 0;
  func_0x80037780(0x5011600,0,iVar1 + 0x38,&local_10);
  local_10 = 0;
  local_e = 200;
  local_c = 0;
  func_0x80037780(0x5011600,0,iVar1 + 0x1b0,&local_10);
  local_10 = 0;
  local_e = 0;
  local_c = 0xff9c;
  func_0x80037780(0x5011200,0,iVar1 + 0x328,&local_10);
  return;
}
