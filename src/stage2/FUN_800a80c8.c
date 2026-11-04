/* FUN_800a80c8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a80c8  body 0x800a80c8..0x800a8247  size 384 B
 * body sha256 5261b030993c4513376eab0336227cf1e1aca46d87f623b4f3005a0c6e5db886
 * provider record sha256 531fa206401d2a43d38dda5a7c11295a542b2fec291b53d9088c9228415c946f
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_800a80c8(undefined4 param_1)

{
  undefined2 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  puVar2 = (undefined4 *)&DAT_80144448;
  _DAT_80144444 = 0x2800;
  _DAT_80144030 = 0x1800;
  DAT_80147fa9 = 0;
  _DAT_80147fa4 = param_1;
  do {
    puVar2[0x18] = 0xffffffff;
    *puVar2 = 0;
    puVar2[9] = 0;
    puVar2[10] = 0;
    *(undefined1 *)((int)puVar2 + 0x2e) = 0;
    *(undefined2 *)(puVar2 + 0x1a) = 0;
    *(undefined1 *)((int)puVar2 + 0x4a) = 0xff;
    puVar2[0xc] = 0;
    *(undefined1 *)((int)puVar2 + 0x99) = 0x80;
    *(undefined1 *)((int)puVar2 + 0x9a) = 0;
    puVar2[0xe] = 0x3f0000;
    puVar2[0x10] = 0;
    puVar2[0x11] = 0;
    *(undefined1 *)(puVar2 + 0x12) = 0;
    *(undefined1 *)((int)puVar2 + 0x49) = 0;
    *(undefined1 *)((int)puVar2 + 0xbd) = 0;
    *(undefined1 *)((int)puVar2 + 0xbe) = 0x17;
    puVar2[0x5b] = 0;
    *(undefined2 *)(puVar2 + 0x5c) = 0;
    puVar2[0x5e] = 0;
    *(undefined2 *)(puVar2 + 0x5f) = 0;
    puVar2[0x23] = 500;
    *(undefined1 *)(puVar2 + 0x26) = 0;
    iVar3 = iVar3 + 1;
    puVar2 = puVar2 + 0x68;
  } while (iVar3 < 0x20);
  iVar3 = 0;
  puVar2 = (undefined4 *)&DAT_80147aa0;
  do {
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[3] = 0;
    *(undefined1 *)(puVar2 + 5) = 4;
    puVar2[6] = 0x7f0000;
    iVar3 = iVar3 + 1;
    puVar2 = puVar2 + 10;
  } while (iVar3 < 0x20);
  DAT_80147f8c = 1;
  iVar4 = 0;
  iVar3 = 0x398;
  do {
    (&DAT_80147ab4)[iVar3] = 0;
    iVar4 = iVar4 + 1;
    iVar3 = iVar3 + 0x28;
  } while (iVar4 < 8);
  _DAT_80147de8 = 0x7f0000;
  _DAT_80147e10 = 0x7f0000;
  FUN_800af080();
  FUN_800aeccc();
  iVar3 = 0xf;
  puVar1 = (undefined2 *)&DAT_80147fce;
  do {
    *puVar1 = 0;
    iVar3 = iVar3 + -1;
    puVar1 = puVar1 + -1;
  } while (-1 < iVar3);
  FUN_800b1a98();
  return;
}
