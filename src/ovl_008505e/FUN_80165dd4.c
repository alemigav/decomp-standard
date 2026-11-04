/* FUN_80165dd4
 * image   ovl_008505e (ovl), base 0x80161cf0
 * address 0x80165dd4  body 0x80165dd4..0x80165e7f  size 172 B
 * body sha256 15ffa8777f79112b84520109b7767243d88661b632d6d0efecfca03f68cad0d8
 * provider record sha256 9ef7fe9c038bcc64dccea8ecee324004fcbe68ac9a660d79787943838897398c
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165dd4(int param_1)

{
  undefined2 uVar1;
  byte *pbVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  
  *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 1;
  pbVar2 = &DAT_80166f50;
  uVar5 = 0;
  do {
    puVar3 = (uint *)(*(int *)(param_1 + 0x234) + (uint)*pbVar2 * 0x178);
    uVar4 = *puVar3;
    if ((DAT_800e9012 & 8) != 0) {
      uVar4 = uVar4 | 0x4a;
    }
    *puVar3 = uVar4;
    uVar1 = *(undefined2 *)(param_1 + 0x66);
    uVar4 = uVar5 + 1;
    *(undefined2 *)(puVar3 + 0x4e) = 0;
    *(undefined2 *)(puVar3 + 0x4d) = 800;
    *(undefined2 *)((int)puVar3 + 0x132) = 0xff6a;
    *(undefined2 *)((int)puVar3 + 0x136) = 10;
    *(undefined2 *)(puVar3 + 0x4f) = 0xff9c;
    puVar3[0x18] = 0x101040;
    *(undefined2 *)(puVar3 + 0x4c) = uVar1;
    pbVar2 = &DAT_80166f51 + uVar5;
    uVar5 = uVar4;
  } while (uVar4 < 7);
  return;
}
