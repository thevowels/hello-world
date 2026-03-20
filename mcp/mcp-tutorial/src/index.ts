import { McpServer } from "@modelcontextprotocol/sdk/server/mcp.js";
import { StdioServerTransport } from "@modelcontextprotocol/sdk/server/stdio.js";
import { z } from "zod";

const server = new McpServer({
  name: "mcp-tutorial",
  version: "1.0.0",
});

server.registerTool(
  "addition",
  {
    description: "Add two numbers",
    inputSchema: {
      a: z.number().describe("First Number"),
      b: z.number().describe("Second Number"),
    },
  },
  ({ a, b }) => {
    return {
      content: [
        {
          type: "text",
          text: `Total is ${a + b}`,
        },
      ],
    };
  }
);

server.registerTool(
  "get_github_repos",
  {
    description: "Get Github Repositories of given username",
    inputSchema: {
      username: z.string().describe("Github Username"),
    },
  },
  async ({ username}) => {
    const res = await fetch(`https://api.github.com/users/${username}/repos`, {
      headers: { "User-Agent": "MCP-Server" },
    });

    if (!res.ok) throw new Error("Error on Github api call.");

	const repos = await res.json();
	const repoList = repos.map((repo:any, index:number)=> `${index}, ${repo.name}`).join("\n\n");
    return {
      content: [{ type: "text", text: repoList }],
    };
  }
);

async function main() {
  const transport = new StdioServerTransport();
  await server.connect(transport);
  console.error("MCP server is running now");
}

main().catch((error) => {
  console.error("Fatal error in main():", error);
  process.exit(1);
});
